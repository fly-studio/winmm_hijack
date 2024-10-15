#pragma once
#include <vector>
#include <wtypes.h>

struct HookFunc {
	PVOID* pFunc;
	PVOID pHook;
};

BOOL hook(const std::vector<HookFunc>& funcList);
BOOL unhook(const std::vector<HookFunc>& funcList);