#include "../hook/inject.h"
#include "winmm.h"




std::vector<HMODULE> g_InjectDlls{};
HMODULE g_hCurrentModule = NULL;


BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        g_hCurrentModule = hModule;
        DisableThreadLibraryCalls(hModule);
        if (!NsLoad())
            return FALSE;

        g_InjectDlls = LoadInjectDlls(hModule);
    }
    break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
    {
        UnloadInjectDlls(g_InjectDlls);
    }
    break;
    }
    return TRUE;
}
