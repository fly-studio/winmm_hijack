
#include "detours.h"
#include "hook.h"


bool hook(PVOID* originalFunc, PVOID hookFunc)
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(originalFunc, hookFunc);
    return DetourTransactionCommit() != 0;
}

bool unhook(PVOID* originalFunc, PVOID hookFunc)
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourDetach(originalFunc, hookFunc);
    return DetourTransactionCommit() != 0;
}
