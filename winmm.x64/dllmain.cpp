#include <windows.h>
#include "NsHiJack.h"
#include "../hook/inject.h"

std::vector<HMODULE> g_InjectDlls{};

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                      )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		{
			if (!NsInitDll())
				return false;

			g_InjectDlls = LoadInjectDlls(hModule);
		}
        break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		{
			UnloadInjectDlls(g_InjectDlls);
		}
		break;
	}
	return TRUE;
}
