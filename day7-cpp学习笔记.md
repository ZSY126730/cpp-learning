# Day7 Markdown笔记：for循环、break、continue、嵌套循环

## 📖今日知识点

1. **for循环语法**

```
for(初始化; 循环条件; 更新变量)
{
    循环体;
}
```

执行顺序：

1. 初始化（只执行1次）
2. 判断条件，条件成立执行循环体；不成立直接跳出循环
3. 执行更新变量
4. 回到第二步判断条件

示例：

```
// 输出1~10
for(int i = 1; i <=10; i++)
{
    cout << i << " ";
}
```

2. break

- **直接跳出整个循环**，循环彻底结束，不再执行
- 常用于找到目标就停止

3. continue

- **跳过本次循环剩下代码，直接进入下一轮循环**
- 不会终止循环

4. 嵌套循环

- 循环里面再写一层循环；外层循环走1次，内层循环完整跑完一轮
- 九九乘法表就是典型嵌套for循环案例

5. 转义字符

- `\t`：Tab制表符，跳到下一个制表位，**用来对齐输出表格**
- `" "`普通空格：仅占1个字符位置，数据长度不一样时排版会错位
- `\n`：换行
- `endl`：换行+刷新输出缓冲区

## 💻练习代码片段

### 练习1 for基础

```
#include <iostream>
using namespace std;

int main()
{
    for(int i = 1; i <= 10; i++)
    {
        cout << i << " ";
    }
    return 0;
}
```

### 练习2 break使用

```
#include <iostream>
using namespace std;

int main()
{
    for(int i = 1; i <= 10; i++)
    {
        if(i == 5)
        {
            break;
        }
        cout << i << " ";
    }
    return 0;
}
//输出：1 2 3 4
```

### 练习3 continue使用

```
#include <iostream>
using namespace std;

int main()
{
    for(int i = 1; i <= 10; i++)
    {
        if(i == 5)
        {
            continue;
        }
        cout << i << " ";
    }
    return 0;
}
//输出：1 2 3 4 6 7 8 9 10，跳过5
```

### Part5 九九乘法表（嵌套循环）

```
#include <iostream>
using namespace std;

int main()
{
    for(int i = 1; i <= 9; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cout << j << "*" << i << "=" << i*j << "\t";
        }
        cout << endl;
    }
    return 0;
}
```

> 
> ✨踩坑记录
> 
> 
> 1. 把`\t`替换成普通空格`" "`：算式长短不一，乘法表竖列无法对齐，排版混乱。
> 2. 嵌套循环千万注意内外层循环变量不要都写i，必须区分 i、j。

## ⚠️常见报错&坑

1. for循环分号：`for(int i=0; i<10; i++)` 括号内是**两个分号**，不能多、不能少
2. 嵌套循环变量重名：内外层不能都用i，会逻辑错乱
3. break和continue只对**当前所在最内层循环**生效，不会跳出外层循环

## 📝编译&git提交命令

```
g++ for-test.cpp -o for-test.exe
.\for-test.exe

# git操作
git add .
git commit -m "day7 for循环、嵌套循环、九九乘法表"
git push
```