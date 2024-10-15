# winmm.dll hijack & DLL Injection & Hook

劫持`winmm.dll`，并注入指定的dll，如果dll有实现`GetHookFuncList`函数，将会调用Detours进行函数劫持。

待劫持目标exe的导入表`IAT（Import Address Table）`中必须有`winmm.dll`，才能劫持成功。

> 检测目标exe的位数和`IAT`，使用：[Detect it easy](https://github.com/horsicq/Detect-It-Easy)


## 工作原理：

1. 先劫持目标exe，注入`winmm.dll`
2. `winmm.dll`查找当前目录，依次注入自定义的dll，比如：`wimm.your.dll`
3. 如果在`wimm.your.dll`中有实现的`GetHookFuncList`函数，则使用`Detours`进行函数劫持。


## FAQ
1. `winmm.your.dll`自己调用Detours实现Hook，可以吗？
    当然可以，dll都注入到目标exe了，你可以实现所有你想做的任何事情。

2. 既然如此，那为什么要在`winmm.your.dll`中导出`GetHookFuncList`，然后在`winmm.dll`中做Hook？
    1. 简化步骤，编译detours很麻烦，一般在VisualC++中才能编译成功。
    2. `winmm.your.dll`可以是其它编译器环境的程序，比如、mingw32、clang。（后期会支持其它语言）

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

### Hook 函数如何实现

比如需要Hook住`CreateFileW`这个WindowsAPI，那么需要如下操作：

在winmm.core.dll的项目中添加如下代码：

hook.h文件
```cpp
#pragma once
#include <vector>

struct HookFunc {
	PVOID* pFunc;
	PVOID pHook;
};


#ifdef __cplusplus
extern "C" {
#endif


std::vector<HookFunc> GetHookFuncList();


#ifdef __cplusplus
}
#endif
```

> 目前暂时使用std::vector为返回值，后续会修改为C的结构，以便在其它语言都可以劫持函数。

hook.cpp文件
```cpp
#include "hook.h"
#include <Windows.h>


// 原始 CreateFileW 函数的类型定义
typedef HANDLE(WINAPI* CREATEFILEW)(
    LPCWSTR lpFileName,
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile
    );


// 原始 CreateFileW 函数的指针
CREATEFILEW RealCreateFileW = CreateFileW;

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

// 返回哪些函数需要被Hook
std::vector<HookFunc> GetHookFuncList() {

    std::vector<HookFunc> hookFuncList{};
    hookFuncList.push_back(HookFunc{ &(PVOID&)RealCreateFileW, (PVOID)HookCreateFileW });

    return hookFuncList;
}

```
