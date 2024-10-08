# winmm.dll hijack & DLL Injection

劫持`winmm.dll`，并注入指定的dll。

当待劫持目标exe的导入表`IAT（Import Address Table）`中有`winmm.dll`，方可劫持成功。

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