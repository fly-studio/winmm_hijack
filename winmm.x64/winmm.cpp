#include <windows.h>
#include <vector>
#include <tchar.h>
#include <algorithm>
#include <string>

#include "NsHiJack.h"

using tstring = std::basic_string<TCHAR, std::char_traits<TCHAR>, std::allocator<TCHAR>>;

static tstring GetCurrentDllDir(HMODULE hModule = NULL)
{
    if (NULL == hModule) {
        hModule = GetModuleHandle(NULL); // 获取调用者的模块句柄
    }
    TCHAR pathBuffer[MAX_PATH] = { 0 };
    // 获取包含文件名的完整路径
    if (GetModuleFileName(hModule, pathBuffer, MAX_PATH) == 0) {
        return {};
    }

    // 查找最后一个反斜杠的位置
    TCHAR* lastSlash = _tcsrchr(pathBuffer, _T('\\'));
    if (lastSlash == NULL) {
        return _T("");
    }
    *lastSlash = '\0';

    return tstring(pathBuffer);
}

static void LoadInjectDlls(HMODULE hModule = NULL) {
    TCHAR output[1024];

    tstring currentDir = GetCurrentDllDir();

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

    _stprintf_s(output, _countof(output), TEXT("Found %I64u dlls for injection."), fileList.size());
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

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                      )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		{
			if (!NsInitDll())
				return false;

			LoadInjectDlls(hModule);
		}
        break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
