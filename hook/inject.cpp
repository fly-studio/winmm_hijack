#include "inject.h"
#include <algorithm>
#include <regex>
#include "utils.h"
#include <tchar.h>


std::vector<HMODULE> LoadInjectDlls(HMODULE hModule) {
    TCHAR output[2048];

    std::filesystem::path dllPath = GetCurrentDllPath(hModule);
    std::vector<std::filesystem::path> dllList;

    std::basic_regex<TCHAR> pattern(_T("^winmm\\..+\\.dll$"));
    for (const auto& entry : std::filesystem::directory_iterator(dllPath.parent_path())) {
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

    std::vector<HMODULE> dllModuleList;

    // LoadLibrary排序后的文件列表
    for (const auto& dllPath : dllList) {
        _stprintf_s(output, _countof(output), _T("Try to load dll: %s"), dllPath.c_str());
        OutputDebugString(output);

        HMODULE hModule = LoadLibrary(dllPath.c_str());
        if (hModule) {
            _stprintf_s(output, _countof(output), _T("Injected dll: %s"), dllPath.c_str());
            OutputDebugString(output);


            dllModuleList.push_back(hModule);
        }
    }
    return dllModuleList;
}

void UnloadInjectDlls(const std::vector<HMODULE>& dllModuleList)
{
    for (auto& hModule : dllModuleList) {
        FreeLibrary(hModule);
    }
}