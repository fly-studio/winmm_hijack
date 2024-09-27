
#pragma once

#ifdef _DEBUG
#pragma comment(lib,"x64\\Debug\\NsHiJack.obj")
#else
#pragma comment(lib,"x64\\Release\\NsHiJack.obj")
#endif

extern "C"
{
    bool __cdecl NsInitDll();
}
