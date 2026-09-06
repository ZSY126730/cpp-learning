
# Day6 学习笔记
> 日期：2026‑09‑06
> 工作目录：`D:\cpp\day6`
> 学习内容：while循环，循环执行流程、计数器、累加求和、循环读取用户输入、死循环；初步了解for循环；区分if与while；`endl`换行作用
> .gitignore 忽略exe文件，编译统一使用 `-Wall` 参数

## 一、环境准备
```powershell
mkdir day6
cd day6
```

## 二、练习1 while1.cpp while基础循环，打印1~10

```
#include <iostream>
using namespace std;

int main()
{
    int i = 1;   // 计数器，初始化
    while(i <= 10)  // 循环条件：true执行循环体；false退出循环
    {
        cout << i << " "; // " "输出空格，分隔数字，不换行
        i = i + 1;  // 计数器自增，必不可少，缺少会造成死循环
    }
    cout << endl; // 全部输出完成后换行
    return 0;
}
```

编译运行

```
g++ -Wall while1.cpp -o while1.exe
.\while1.exe
```

输出：`1 2 3 4 5 6 7 8 9 10 `

### while执行流程

1. 判断while括号内条件
2. 条件为true，执行大括号循环体代码
3. 执行完循环体，回到第二步再次判断条件
4. 条件为false，跳出循环，执行循环后面代码

> 
> ⚠️重要区分

- `if()`：只判断执行**一次**，不会自动重复
- `while()`：条件成立就反复执行大括号内代码

## 三、练习2 while2.cpp 累加求和，1+2+…+100

```
#include <iostream>
using namespace std;

int main()
{
    int i = 1;
    int sum = 0;  // 累加变量初始值必须为0

    while(i <= 100)
    {
        sum = sum + i;
        i = i + 1;
    }
    cout << "1到100总和 = " << sum << endl;
    return 0;
}
```

编译运行

```
g++ -Wall while2.cpp -o while2.exe
.\while2.exe
```

输出：`1到100总和 = 5050`

> 
> 要点：存储总和的变量sum一定要初始化，不能直接不赋值就使用。

## 四、练习3 while3.cpp 循环读取用户输入，输入0结束

```
#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "请输入数字，输入0结束程序：" << endl;
    cin >> num;

    while(num != 0)   // num不等于0就继续循环
    {
        cout << "你输入的数字是：" << num << endl;
        cin >> num;  // 循环内部再次读取输入
    }
    cout << "程序结束" << endl;
    return 0;
}
```

编译运行

```
g++ -Wall while3.cpp -o while3.exe
.\while3.exe
```

交互示例

```
请输入数字，输入0结束程序：
5
你输入的数字是：5
9
你输入的数字是：9
0
程序结束
```

## 五、练习4 bug‑while.cpp 体验死循环

```
#include <iostream>
using namespace std;

int main()
{
    int i = 1;
    while(i <= 10)
    {
        cout << i << " ";
        // 故意删除 i = i + 1;
    }
    return 0;
}
```

编译运行

```
g++ -Wall bug-while.cpp -o bug-while.exe
.\bug-while.exe
```

现象：无限打印数字1。

> 
> 终止死循环快捷键：`Ctrl + C`
> 死循环成因：循环条件永远无法变为false。

## 六、拓展练习 even.cpp 输出1‑20全部偶数

### 写法1：遍历全部数字，if判断偶数

```
#include <iostream>
using namespace std;
int main(){
    int i=1;
    while(i<=20)
    {
        if(i%2==0)
        {
            cout<<i<<" ";
        }
        i=i+1; // 计数器写在if外面，每一轮循环都执行，防止死循环
    }
    cout << endl;
    return 0;
}
```

### 写法2：直接从2开始，每次+2，无需if

```
#include <iostream>
using namespace std;
int main(){
    int i = 2;
    while(i <= 20)
    {
        cout << i << " ";
        i = i + 2;
    }
    cout << endl;
    return 0;
}
```

输出：`2 4 6 8 10 12 14 16 18 20 `

> 
> `i%2 == 0` → 偶数；`i%2 ==1` → 奇数

### 关于 cout << endl;

1. `endl`：换行，把光标跳到下一行开头。
2. 如果不写`endl`：程序输出正确，但是PowerShell提示符会直接粘在输出数字同一行末尾，排版难看。
3. `" "`只是输出空格，**只隔开数字，不换行**。

## 七、拓展：for循环基础

for与while逻辑等价，可以互相转换。

```
// for(①初始化; ②循环条件; ③循环末尾执行)
for(int i = 1; i <= 20; i = i + 1)
{
    if(i%2 == 0)
    {
        cout << i << " ";
    }
}
```

简写：`i = i +1` 等价于 `i++`

### for 和 while 如何选择

1. **for循环：适合循环次数明确**，初始化、条件、自增写在同一行，一目了然。
2. **while循环：适合循环次数不确定**，比如等待用户输入特定值才退出。> 
> 二者性能无差别，只是写法方便程度不同。

## 八、今日踩坑记录

1. 想用循环，只写了`if`，代码只会执行一次，没有循环效果。
2. 计数器自增语句写进if内部，只有满足条件才自增，直接死循环。
3. 忘记写`i=i+1`，while条件永远成立，死循环，使用`Ctrl+C`强制结束。
4. 缺少末尾`endl`，终端提示符和输出挤在同一行。

## 九、Git提交（退回D:\cpp）

```
cd ..
git add .
git commit -m "Day6：while循环，计数器，累加求和，输入循环，死循环成因与Ctrl+C终止，初步了解for循环"
git push
```

## 今日总结

1. while：先判断条件，条件成立执行循环体；if只执行一次。
2. 计数器自增语句要保证每一轮循环都执行，避免死循环。
3. 累加变量初始值设置为0。
4. `" "`输出空格，`endl`实现换行。
5. for适合已知循环次数；while适合未知循环次数。

```