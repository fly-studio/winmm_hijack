# winmm.dll hijack & DLL Injection & Hook

劫持`winmm.dll`，并注入指定的dll。

待劫持目标exe的导入表`IAT（Import Address Table）`中必须有`winmm.dll`，才能劫持成功。

> 检测目标exe的位数和`IAT`，使用：[Detect it easy](https://github.com/horsicq/Detect-It-Easy)


## Build

编译项目Release，会生两个文件，分别为
- winmm.x86.dll
- winmm.x64.dll


## Usage

1. 假设目标exe是x86的，就修改`winmm.x86.dll`为`winmm.dll`，放入该程序的目录下
2. 待注入的dll命名需要为`winmm.xxx.dll`，放入同目录。

    支持多个dll，例如：

    ```
    winmm.core.dll
    winmm.module.dll
    ```
3. 加载顺序是简单的字典顺序，比如`winmm.a.dll` 优先于 `winmm.b.dll`

4. 是否加载成功，使用[DebugView](https://learn.microsoft.com/en-us/sysinternals/downloads/debugview)查看

    输出如下，表示`winmm.core.dll`注入成功
    ```
    Injected dll: winmm.core.dll
    ```

## Development

1. 可以使用[Baymax Patch Tools](https://www.chinapyg.com/thread-83083-1-1.html)、[AHeadLibEx](https://github.com/i1tao/AheadLibEx)生成的劫持的源码
  
    比如系统DLL：`winhttp.dll`、`version.dll`。


2. 需要分别生成x86和x64的源码，
    - 系统x64的dll位于：`C:\Windows\System32`
    - 系统x86的dll位于`C:\Windows\SysWOW64`

    - x86的只会生成一个.cpp
    - x64的会生成.cpp、.asm，导出的函数的代码实际上位于.asm

## 导出的方法

winmm.dll中导出了3个简单的hook方法：

```cpp
long hook(PVOID* originalFunc, PVOID hookFunc);
long unhook(PVOID* originalFunc, PVOID hookFunc);
long hookTransaction(HANDLE threadHandle, void (*callback)(void));
```

除此之外，还导出了Detours的所有方法：

```cpp
LONG WINAPI DetourTransactionBegin(VOID);
LONG WINAPI DetourTransactionCommit(VOID);
LONG WINAPI DetourTransactionAbort(VOID);
LONG WINAPI DetourUpdateThread(HANDLE hThread);
LONG WINAPI DetourAttach(PVOID *ppPointer, PVOID pDetour);
LONG WINAPI DetourAttachEx(PVOID *ppPointer, PVOID pDetour, PDETOUR_TRAMPOLINE *ppRealTrampoline, PVOID *ppRealTarget, PVOID *ppRealDetour);
LONG WINAPI DetourDetach(PVOID *ppPointer, PVOID pDetour);

BOOL WINAPI DetourCreateProcessWithDllExA(LPCSTR lpApplicationName, LPSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCSTR lpCurrentDirectory, LPSTARTUPINFOA lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation, LPCSTR lpDllName, PDETOUR_CREATE_PROCESS_ROUTINEA pfCreateProcessA);
BOOL WINAPI DetourCreateProcessWithDllExW(LPCWSTR lpApplicationName, LPWSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCWSTR lpCurrentDirectory, LPSTARTUPINFOW lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation, LPCSTR lpDllName, PDETOUR_CREATE_PROCESS_ROUTINEW pfCreateProcessW);

BOOL WINAPI DetourCreateProcessWithDllsA(LPCSTR lpApplicationName, LPSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCSTR lpCurrentDirectory, LPSTARTUPINFOA lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation, DWORD nDlls, LPCSTR *rlpDlls, PDETOUR_CREATE_PROCESS_ROUTINEA pfCreateProcessA);
BOOL WINAPI DetourCreateProcessWithDllsW(LPCWSTR lpApplicationName, LPWSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCWSTR lpCurrentDirectory, LPSTARTUPINFOW lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation, DWORD nDlls, LPCSTR *rlpDlls, PDETOUR_CREATE_PROCESS_ROUTINEW pfCreateProcessW);

BOOL WINAPI DetourRestoreAfterWith(VOID);
BOOL WINAPI DetourFinishHelperProcess(HANDLE hProcess, DWORD dwProcessId, BOOL fFinishedProcess);

PVOID WINAPI DetourBinaryOpen(HANDLE hFile);
VOID WINAPI DetourBinaryClose(PVOID pBinary);
BOOL WINAPI DetourBinaryWrite(HANDLE hFile, PVOID pBinary);
BOOL WINAPI DetourBinaryResetImports(PVOID pBinary);
BOOL WINAPI DetourBinaryEditImports(PVOID pBinary, PVOID pContext, PF_DETOUR_BINARY_BYWAY_CALLBACK pfByway, PF_DETOUR_BINARY_FILE_CALLBACK pfFile, PF_DETOUR_BINARY_SYMBOL_CALLBACK pfSymbol, PF_DETOUR_BINARY_COMMIT_CALLBACK pfCommit);

PVOID WINAPI DetourAllocateRegionWithinJumpBounds(PVOID pbTarget, LONG cbAllocate);
PVOID WINAPI DetourCopyInstruction(PVOID pDst, PVOID *ppDstPool, PVOID pSrc, PVOID *ppTarget, LONG *plExtra);

BOOL WINAPI DetourSetCodeModule(HMODULE hModule, BOOL fLimitReferencesToModule);
BOOL WINAPI DetourSetIgnoreTooSmall(BOOL fIgnore);
BOOL WINAPI DetourSetRetainRegions(BOOL fRetain);
BOOL WINAPI DetourSetSystemRegionLowerBound(PVOID pSystemRegionLowerBound);
BOOL WINAPI DetourSetSystemRegionUpperBound(PVOID pSystemRegionUpperBound);

PVOID WINAPI DetourGetEntryPoint(HMODULE hModule);
ULONG WINAPI DetourGetModuleSize(HMODULE hModule);
HMODULE WINAPI DetourEnumerateModules(HMODULE hModuleLast);
ULONG WINAPI DetourGetSizeOfPayloads(HMODULE hModule);


PVOID WINAPI DetourFindPayload(HMODULE hModule, REFGUID rguid, DWORD *pcbData);
PVOID WINAPI DetourGetContainingModule(PVOID pvAddr);

BOOL WINAPI DetourEnumerateImports(HMODULE hModule, PVOID pContext, PF_DETOUR_IMPORT_FILE_CALLBACK pfImportFile, PF_DETOUR_IMPORT_FUNC_CALLBACK pfImportFunc);
BOOL WINAPI DetourEnumerateExports(HMODULE hModule, PVOID pContext, PF_DETOUR_ENUMERATE_EXPORT_CALLBACK pfExport);
```

## Example: Hook 系统函数

比如需要hook `CreateFileW`，则在`winmm.xxx.dll`的`dllmain.cpp`中参考如下：


```cpp
#include <Windows.h>

// 申明父级winmm.dll的函数
#define BindDllMethod(funcPtr, dllHandle, funcName) (funcPtr = (decltype(funcPtr))GetProcAddress(dllHandle, funcName))
long (*hookTransaction)(HANDLE threadHandle, void (*callback)(void)) = nullptr;
long (*hook)(PVOID* originalFunc, PVOID hookFunc) = nullptr;
long (*unhook)(PVOID* originalFunc, PVOID hookFunc) = nullptr;


// 原始 CreateFileW 函数的指针
auto RealCreateFileW = CreateFileW;

// 钩子函数
static HANDLE WINAPI HookedCreateFileW(
    LPCWSTR lpFileName,
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile
)
{
    // 做你想做的事情

    // 调用原始的 CreateFileW 函数
    HANDLE hFile = RealCreateFileW(
        lpFileName,
        dwDesiredAccess,
        dwShareMode,
        lpSecurityAttributes,
        dwCreationDisposition,
        dwFlagsAndAttributes,
        hTemplateFile
    );

    // 做你想做的事情

    return hFile;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH: {
            HMODULE hModule = GetModuleHandle("winmm.dll");
            if (nullptr == hModule) { // 当前dll不是被 winmm.dll 加载的，无法hook
                return;
            }
            // 绑定
            BindDllMethod(hookTransaction, hModule, "hookTransaction");
            BindDllMethod(hook, hModule, "hook");
            BindDllMethod(unhook, hModule, "unhook");

            if (hookTransaction != nullptr) {
                hookTransaction(NULL, [](){
                    hook(&(PVOID&)RealCreateFileW, (PVOID)HookCreateFileW);
                    // ...
                });
            }
            
        } break;
        case DLL_PROCESS_DETACH: {
            if (hookTransaction != nullptr) {
                hookTransaction(NULL, [](){
                    unhook(&(PVOID&)RealCreateFileW, (PVOID)HookCreateFileW);
                    // ...
                });
            }
        }
        break;
    }
}

#undef BindDllMethod // 避免影响其他模块

```