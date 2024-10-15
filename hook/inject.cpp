#include "inject.h"
#include <algorithm>
#include <regex>
#include "hook.h"
#include "utils.h"
#include <tchar.h>

namespace fs = std::filesystem;

static std::vector<HookFunc> tryGetHookFuncList(HMODULE hModule)
{
    typedef std::vector<HookFunc>(*PFnHookFuncList)();
    auto fn = (PFnHookFuncList)GetProcAddress(hModule, "GetHookFuncList");
    if (NULL != fn) {
        auto hookList = fn();
        return hookList;
    }
    return {};
}


std::vector<DllInfo> LoadInjectDlls(HMODULE hModule) {
    TCHAR output[2048];

    fs::path dllPath = GetCurrentDllPath(hModule);
    std::vector<fs::path> dllList;

    std::basic_regex<TCHAR> pattern(_T("^winmm\\..+\\.dll$"));
    for (const auto& entry : fs::directory_iterator(dllPath.parent_path())) {
        if (entry.is_regular_file()){
            auto filename = entry.path().filename();
            if (std::regex_match(filename.c_str(), pattern)) {
                dllList.push_back(entry.path());
            }
        }
    }

    if (dllList.empty()) {
        // 没有搜索到文件
        OutputDebugString(_T("Found nothing for injection"));
        return {};
    }
    
    // 对文件列表进行字典顺序排序
    std::sort(dllList.begin(), dllList.end());

    _stprintf_s(output, _countof(output), _T("Found %zu dlls for injection."), dllList.size());
    OutputDebugString(output);

    std::vector<DllInfo> dllInfoList{};
    // LoadLibrary排序后的文件列表
    for (const auto& dllPath : dllList) {
        _stprintf_s(output, _countof(output), _T("Try to load dll: %s"), dllPath.c_str());
        OutputDebugString(output);

        HMODULE hModule = LoadLibrary(dllPath.c_str());
        if (hModule) {
            _stprintf_s(output, _countof(output), _T("Injected dll: %s"), dllPath.c_str());
            OutputDebugString(output);

            // hook functions
            auto hookFuncList = tryGetHookFuncList(hModule);
            if (!hook(hookFuncList)) {
                _stprintf_s(output, _countof(output), _T("Failed to hook, dll: %s"), dllPath.c_str());
                OutputDebugString(output);
            }


            dllInfoList.push_back({ hModule, hookFuncList });
        }
    }
    return dllInfoList;
}

void UnloadInjectDlls(const std::vector<DllInfo>& dllList)
{
    for (auto& dll : dllList) {
        unhook(dll.hooks);
        FreeLibrary(dll.hModule);
    }
}