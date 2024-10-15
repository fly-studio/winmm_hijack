#pragma once
#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容

#include <string>
#include <tchar.h>
#include <windows.h>

using tstring = std::basic_string<TCHAR, std::char_traits<TCHAR>, std::allocator<TCHAR>>;

tstring GetCurrentDllDir(HMODULE hModule);
