# winmm.dll hijack & DLL Injection

使用[Baymax Patch Tools](https://www.chinapyg.com/thread-83083-1-1.html)生成的劫持`winmm.dll`源码，项目为Visual Studio 2020

可劫持目标exe的导入表`IAT（Import Address Table）`中有`winmm.dll`的情况

## Build

编译项目Release，会生两个文件，分别为
- winmm.x86.dll
- winmm.x64.dll


## Usage

1. 假设目标exe是x86的，就修改`winmm.x86.dll`为`winmm.dll`，放入该程序的目录下

2. 然后在同目录新建`inject.txt`，写入如下内容：

    ```
    your1.dll
    your2.dll
    ```

    - 你需要注入几个dll，就写几个，使用换行区分。
    - 支持绝对路径，比如：`C:\your\path\to\your1.dll`
    - 如果`inject.txt`不存在，会跳过注入
    - 如果dll的路径不在，也会跳过注入该dll

3. 检测目标exe的位数和`IAT`，使用：[Detect it easy](https://github.com/horsicq/Detect-It-Easy)