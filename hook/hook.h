#pragma once
#include <wtypes.h>
#include "library.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 *  事务，可以在callback中执行hook、unhook
 * 
 * @param threadHandle 线程句柄，传入NULL表示当前线程
 * @param callback 可以在回调中执行hook、unhook
 * @return 执行结果, 0: NO_ERROR
 * 
 * @code
 * hookTransaction(NULL, [](){
 *		hook(&(PVOID&)RealCreateFileW, (PVOID)HookCreateFileW);
 * 
 * });
 * @endcode
 */
long hookTransaction(HANDLE threadHandle, void (*callback)(void));

// 勾住函数，必须在hookTransaction中执行
long hook(PVOID* originalFunc, PVOID hookFunc);
// 解除勾住函数，必须在hookTransaction中执行
long unhook(PVOID* originalFunc, PVOID hookFunc);

#ifdef __cplusplus
}
#endif