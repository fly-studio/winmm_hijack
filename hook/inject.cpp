#include "load.h"

#include "utils.h"
#include <vector>
#include <algorithm>


void LoadInjectDlls(HMODULE hModule) {
    TCHAR output[1024];

    tstring currentDir = GetCurrentDllDir(hModule);

    // 构造目录搜索模式
    tstring searchPattern = currentDir + _T("\\winmm.*.dll");
    // 开始搜索
    WIN32_FIND_DATA findData;
    HANDLE hFind = FindFirstFile(searchPattern.c_str(), &findData);
    // 没有搜索到文件
    if (hFind == INVALID_HANDLE_VALUE) {
        OutputDebugString(_T("Found nothing for injection"));
        return;
    }

    // 遍历搜索结果
    std::vector<tstring> fileList;
    do {
        // 添加到列表中
        fileList.push_back(findData.cFileName);
    } while (FindNextFile(hFind, &findData));

    // 关闭句柄
    FindClose(hFind);

    // 对文件列表进行字典顺序排序
    std::sort(fileList.begin(), fileList.end());

    _stprintf_s(output, _countof(output), TEXT("Found %zu dlls for injection."), fileList.size());
    OutputDebugString(output);

    // LoadLibrary排序后的文件列表
    for (const auto& dllPath : fileList) {
        _stprintf_s(output, _countof(output), TEXT("Try to load dll: %s"), dllPath.c_str());
        OutputDebugString(output);

        HMODULE hModule = LoadLibrary(dllPath.c_str());
        if (hModule) {
            _stprintf_s(output, _countof(output), TEXT("Injected dll: %s"), dllPath.c_str());
            OutputDebugString(output);
        }

    }
}