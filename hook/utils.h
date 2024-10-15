#pragma once
#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容

#include <string>
#include <filesystem>
// #include <tchar.h>
#include <windows.h>


std::filesystem::path GetCurrentDllPath(HMODULE hModule);
