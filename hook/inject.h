#pragma once
#include <windows.h>
#include <vector>
#include "hook.h"

struct DllInfo {
    HMODULE hModule;
    std::vector<HookFunc> hooks;
};

// Load inject dlls
std::vector<DllInfo> LoadInjectDlls(HMODULE hModule);

// Unload inject dlls
void UnloadInjectDlls(const std::vector<DllInfo>& dllList);