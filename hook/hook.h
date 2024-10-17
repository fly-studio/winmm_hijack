#pragma once
#include <wtypes.h>
#include "library.h"

#ifdef __cplusplus
extern "C" {
#endif

DLL_API bool hook(PVOID* originalFunc, PVOID hookFunc);
DLL_API bool unhook(PVOID* originalFunc, PVOID hookFunc);


#ifdef __cplusplus
}
#endif