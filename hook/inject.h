#pragma once
#include <windows.h>
#include <vector>


// Load inject dlls
std::vector<HMODULE> LoadInjectDlls(HMODULE hModule);

// Unload inject dlls
void UnloadInjectDlls(const std::vector<HMODULE>& dllModuleList);