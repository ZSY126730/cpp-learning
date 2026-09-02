# Day1 C++环境熟悉
## 1.环境清单
- VS Code
- MinGW‑w64(g++编译器)，路径 D:\mingw64\bin
- VSCode插件：C/C++ Extension Pack、Error Lens、中文包

## 2.关键操作命令
### 编译
```powershell
g++ hello.cpp -o hello.exe
## 前面是c++对应，中间hello.cpp是编写的程序文件名，后面-o hello.exe是指生成hello.exe文件
### 运行
```powershell
.\hello.exe
## 这一步是运行上面生成的hello.exe文件
## 3. 踩过的坑（重点！自己踩过的一定要记）
❗VS Code 编辑器看到代码，标签页小圆点 = 未保存 Ctrl+S，硬盘文件是空，编译器读硬盘旧文件报 undefined reference to WinMain
现象：三角▶运行按钮可以跑成功，但手动 g++ 编译报错。
原因：三角按钮读取内存里未保存的代码；g++ 读取磁盘保存后的文件。
发现经过：用记事本打开D盘中对应文件为空
❗Windows PowerShell 中文乱码
解决：VS Code 右下角把文件编码从 UTF‑8【通过编码保存】改为 GBK。
提示：widows读UTF8中文会乱码，Linux读GBK中文会乱码，所以后续如果装了WSL2要看一下这个改不改
❗不要只打开单个 cpp 文件，VS Code 必须【打开文件夹】工作。