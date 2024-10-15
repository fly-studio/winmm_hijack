#include "utils.h"


//using tstring = std::basic_string<TCHAR, std::char_traits<TCHAR>, std::allocator<TCHAR>>;
//tstring GetCurrentDllDir(HMODULE hModule/* = NULL */)
//{
//    if (NULL == hModule) {
//        hModule = GetModuleHandle(NULL); // 获取调用者的模块句柄
//    }
//    TCHAR pathBuffer[MAX_PATH] = { 0 };
//    // 获取包含文件名的完整路径
//    if (GetModuleFileName(hModule, pathBuffer, MAX_PATH) == 0) {
//        return {};
//    }
//
//    // 查找最后一个反斜杠的位置
//    TCHAR* lastSlash = _tcsrchr(pathBuffer, _T('\\'));
//    if (lastSlash == NULL) {
//        return _T("");
//    }
//    *lastSlash = '\0';
//
//    return tstring(pathBuffer);
//}

std::filesystem::path GetCurrentDllPath(HMODULE hModule)
{
	if (NULL == hModule) {
        hModule = GetModuleHandle(NULL); // 获取调用者的模块句柄
    }
    TCHAR pathBuffer[MAX_PATH] = { 0 };
    // 获取包含文件名的完整路径
    if (GetModuleFileName(hModule, pathBuffer, MAX_PATH) == 0) {
        return {};
    }

    return std::filesystem::path(pathBuffer);
}
