# Day9 C++二维数组学习笔记

```
# Day9 C++ 二维数组
## 一、二维数组基础概念
二维数组可以理解成**数组里面存放数组**，类似表格，有行、列两个维度。
语法：
```cpp
// 定义
数据类型 数组名[行数][列数];
```

> 
> 注意：C++定义二维数组时，**列数不能省略**；行数可以省略（初始化时自动推导行数）。

### 1. 初始化写法

```
// 写法1：完整初始化
int arr[2][3] = {
    {1,2,3},
    {4,5,6}
};

// 写法2：简化初始化（按顺序填充）
int arr[2][3] = {1,2,3,4,5,6};

// 写法3：部分初始化，剩余自动补0
int arr[2][3] = {{1},{2}}; 

// 写法4：行数省略，列必须写，编译器自动算行数
int arr[][3] = {1,2,3,4,5,6};
```

## 二、二维数组访问与遍历

通过 `数组名[行下标][列下标]` 访问元素，下标**从0开始**。
双层for循环遍历：外层循环控制行，内层循环控制列。

```
#include <iostream>
using namespace std;

int main()
{
    int arr[2][3] = {{1,2,3},{4,5,6}};
    // 遍历
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```

## 三、二维数组内存特点

1. 二维数组在内存中**连续存放**，不是分开的两块内存；
2. `arr` 代表整个二维数组首地址；
3. `arr[i]` 代表第i行的首地址；
4. 占用总字节数 = 行数 × 列数 × 单个元素所占字节。

## 四、常用案例

1. 求二维数组所有元素总和
2. 求每行最大值、最小值
3. 矩阵转置（行列互换）

## 五、编译踩坑记录（MinGW重点）

### 坑1：windows.h 和 iostream 冲突 `reference to 'byte' is ambiguous`

> 
> 现象：同时引入`windows.h` + `<iostream>`，大量byte二义性报错
> 原因：

- windows.h 定义全局 `typedef unsigned char byte`
- C++标准库`<cstddef>`（iostream自动引入）定义`std::byte`
两个byte名字冲突。

✅ 解决方法三选一：

1. 把`#include <windows.h>`放到所有C++标准头文件**最前面**

```
#include <windows.h>
#include <iostream>
```

2. 包含windows.h前加宏定义屏蔽冲突

```
#define _WIN32_NO_WINBYTE
#include <windows.h>
#include <iostream>
```

3. 练习二维数组时**直接删掉windows.h**，避开冲突。

### 坑2：控制台中文乱码

两种方案：

#### 方案A：GBK编译（推荐！无windows.h，稳定，不会触发byte冲突）

编译命令增加 `-fexec-charset=GBK`

```
g++ -Wall array2d-3.cpp -o test3.exe -fexec-charset=GBK
```

原理：编译器把源码中文转为GBK，适配Windows控制台默认编码，无需额外头文件。

#### 方案B：UTF8控制台（需要windows.h）

```
#include <windows.h>
#include <iostream>
using namespace std;
int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    cout << "中文测试" << endl;
    return 0;
}
```

要求：

1. cpp文件保存编码为UTF-8
2. PowerShell临时设置输出编码：`[Console]::OutputEncoding = [System.Text.Encoding]::UTF8`，新开终端失效。

## 六、易错点清单

1. 下标从0开始，不要越界访问（越界不会直接报错，但会乱读内存）
2. 定义二维数组，**列数不可省略**，行数可以省略
3. 双层循环：外层行，内层列，不要写反
4. 尽量少在基础练习引入windows.h，容易触发类型名字冲突
5. 编译时如果中文乱码，优先使用 `-fexec-charset=GBK` 参数

## 七、习题方向

1. 输入m行n列二维数组，遍历输出
2. 求二维数组全部元素之和
3. 找出每行最大数字并输出
4. 简单矩阵转置

