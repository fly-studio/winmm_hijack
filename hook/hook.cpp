
#include "detours.h"
#include "hook.h"


long hook(PVOID* originalFunc, PVOID hookFunc)
{
    return DetourAttach(originalFunc, hookFunc);
}

long unhook(PVOID* originalFunc, PVOID hookFunc)
{
    return DetourDetach(originalFunc, hookFunc);
}

bool hookTransaction(HANDLE threadHandle, void(*callback)(void))
{
    if (NULL == threadHandle) {
        threadHandle = GetCurrentThread();
    }
    DetourTransactionBegin();
    DetourUpdateThread(threadHandle);
    callback();
    return DetourTransactionCommit() != 0;
}
