
#include "hook.h"
#include "detours.h"


BOOL hook(const std::vector<HookFunc> &funcList)
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    for (auto &fn : funcList)
    {
        DetourAttach(fn.pFunc, fn.pHook);
    }
    return DetourTransactionCommit() != 0;
}

BOOL unhook(const std::vector<HookFunc>& funcList)
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    for (auto &fn : funcList)
    {
        DetourDetach(fn.pFunc, fn.pHook);
    }
    return DetourTransactionCommit() != 0;
}
