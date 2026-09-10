# Day8 学习笔记：C++一维数组基础

> 
> 目录：D:\cpp\day8
> 编译推荐：`g++ -Wall 文件名.cpp -o 文件名.exe`

## 🎯 学习目标

掌握一维数组定义、初始化、下标访问、循环遍历；实现数组求和、求平均值；理解数组越界风险；了解`printf`与`cout`的区别、`%d`与`\n`含义。

## 一、数组是什么

当需要保存**多个同类型数据**时，如果单独定义一堆变量会很麻烦。数组可以把一组相同类型的数据打包存放在一起，配合循环批量读写。

> 
> 例：保存5个学生成绩，不用写`s1,s2,s3,s4,s5`，直接用数组。

## 二、一维数组语法

### 1. 定义格式

```
数据类型 数组名[元素个数];
```

示例：

```
int arr[5]; // 可以存放5个int整数
```

### 2. 数组下标（重点！）

- 下标**从0开始**
- 5个元素数组：下标 `0,1,2,3,4`
- 最大下标 = 元素个数 - 1
- ❗**数组越界**：访问`arr[5]`属于非法访问，会出现随机值、程序闪退，编译器不一定报错。

### 3. 三种初始化方式

```
// 方式1：全部赋值
int arr[5] = {10,20,30,40,50};

// 方式2：部分初始化，剩下元素自动补0
int arr[5] = {1,2}; // arr[2]=0 arr[3]=0 arr[4]=0

// 方式3：全部清零
int arr[5] = {};
```

## 三、代码练习

### 练习1：数组读写修改 array1.cpp

```
#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {10,20,30,40,50};

    cout << arr[0] << "\n";
    cout << arr[3] << "\n";

    arr[2] = 999;
    cout << arr[2] << "\n";

    return 0;
}
```

输出：

```
10
40
999
```

### 练习2：for循环遍历数组 array2.cpp

```
#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {10,20,30,40,50};
    // i从0开始，i<5，不要写成i<=5
    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}
```

输出：

```
10 20 30 40 50
```

### 练习3：键盘输入存入数组 array3.cpp

```
#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {};
    cout << "请输入5个整数：\n";
    for(int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    cout << "你输入的数字是：";
    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}
```

### 练习4：数组求总分、平均分 array4.cpp

```
#include <iostream>
using namespace std;

int main()
{
    int score[5] = {80,90,77,88,95};
    int sum = 0;
    for(int i = 0; i < 5; i++)
    {
        sum = sum + score[i];
    }
    // 除以5.0得到小数，不要写sum/5（整数除法会丢掉小数）
    double avg = sum / 5.0;
    cout << "总分：" << sum << "\n";
    cout << "平均分：" << avg << "\n";
    return 0;
}
```

## 四、拓展：printf 和 cout

> 
> `printf` 是C语言函数，C++可以兼容使用；`cout` 是C++原生输出。

### printf 头文件

```
#include <cstdio>
```

### printf示例

```
#include <cstdio>
int main()
{
    int score = 95;
    printf("考试分数：%d\n", score);
    return 0;
}
```

- `%d`：占位符，代表**十进制整数int**，用来预留位置填变量。类型写错结果会乱。
- `\n`：换行符，输出完成后光标跳到下一行。

### 常用占位符

- `%d` int整数
- `%f` 浮点数
- `%c` 单个字符
- `%s` 字符串

### printf vs cout

| printf | cout |
| --- | --- |
| 需要占位符`%d`，手动匹配类型 | 自动识别变量类型，不用占位符 |
| 头文件`<cstdio>` | 头文件`<iostream>`，需要`using namespace std;` |
| `\n`换行 | `\n`或者`endl` |

## 五、踩坑总结（重点）

1. 数组下标从0开始，循环条件 `i < 长度`，防止越界。
2. 整数/整数 = 整数，求平均分要除以小数（`5.0`）。
3. 数组只写部分初始化，剩余元素自动为0；不初始化的数组是随机垃圾值。
4. printf占位符必须和变量类型匹配，int对应`%d`，写错会乱码。

## 六、Git提交命令

```
cd ..
git add .
git commit -m "day8 一维数组基础，数组遍历、输入赋值、总分平均分，学习printf"
git push
```

---