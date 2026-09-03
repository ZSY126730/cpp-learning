# Day3 学习笔记

> 
> 日期：2026‑09‑03
> 工作目录：`D:\cpp`
> 学习内容：PowerShell终端基础命令、C++ cin键盘输入、人为制造语法错误练习排错、git基础复用

## 一、PowerShell 常用命令

> 
> 核心概念：**当前工作目录**
> 终端所在哪个文件夹，g++编译器就去哪个文件夹寻找源代码。编译报错很多时候就是终端路径和cpp文件不在一处。

| 命令 | 作用 |
| --- | --- |
| `pwd` | 查看当前所在文件夹完整路径 |
| `ls` | 列出当前文件夹内所有文件、子文件夹 |是小写L不是1
| `mkdir day3` | 创建名为 day3 的子文件夹 |
| `cd day3` | 进入 day3 子文件夹 |
| `cd ..` | 返回上一级文件夹 |

> 
> 注意：git仓库初始化在 `D:\cpp`，**禁止在子文件夹执行 git init**。整个项目只初始化一次。

## 二、C++ 练习 input.cpp

功能：接收键盘输入两个整数，计算加法、乘法

```
#include <iostream>
using namespace std;

int main()
{
    int x,y;
    cout << "请输入两个整数：";
    cin >> x >> y;
    cout << "x+y = " << x+y << endl;
    cout << "x*y = " << x*y << endl;
    return 0;
}
```

### 编译运行命令（终端处于 `D:\cpp\day3>`）

```
g++ input.cpp -o input.exe
.\input.exe
```

运行示例：

```
请输入两个整数：12 34
x+y = 46
x*y = 408
```

## 三、刻意排错练习 bug.cpp

1. 复制 input.cpp 另存为 bug.cpp
2. **故意删掉一行末尾分号**，保存
3. 执行编译：`g++ bug.cpp -o bug.exe`
4. 两处观察报错：
   1. VS Code 右侧 Error Lens 的红色波浪提示
   2. 终端 g++ 的报错信息，重点看报错行号
5. 修改补充分号，重新编译直至跑通

> 
> 训练目标：看得懂编译器报错，不要一看到红字就慌。

## 四、Git 操作（Day3提交上传）

> 
> 已经完成 init / remote 配置，后续只执行三行，终端必须回到仓库根目录 `D:\cpp>`

```
cd ..
git add .
git commit -m "Day3: powershell命令练习，cin输入练习，bug排错练习"
git push
```

## 五、配置 .gitignore 忽略exe文件

1. 在 `D:\cpp` 根目录新建文件，完整名字：`.gitignore`
2. 文件内容：

```
# 忽略所有编译生成的exe可执行文件
*.exe

# Windows系统垃圾文件
*.tmp
*.log
.DS_Store
```

3. 清除git已经追踪过的旧exe（本地文件保留，不上传github）

```
git rm --cached *.exe
git add .
git commit -m "添加gitignore，忽略exe编译产物"
git push
```

4. 验证命令

```
git status
```

> 
> git status 查看将要提交的文件列表，不再出现exe即配置成功。

## 六、今日知识点总结

1. `cin >>` 用于读取键盘输入，`cout <<` 用于控制台输出
2. 终端路径非常关键，编译前确认终端位置
3. git init、git remote add origin **只运行一次**；后续更新只需要 add → commit → push
4. `.gitignore`：告诉git哪些文件不需要上传远程仓库
5. exe是编译产物，本地保留使用，不需要上传GitHub

## 七、踩坑记录

- 不要在子文件夹执行 git init，会破坏仓库
- git add . 末尾小数点不能省略
- `.gitignore` 需要处理已经被git追踪过的旧exe，仅仅写配置不会自动移除旧记录