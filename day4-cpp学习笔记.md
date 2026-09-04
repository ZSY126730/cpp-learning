
# Day4 学习笔记
> 日期：2026‑09‑04
> 工作目录：`D:\cpp\day4`
> 学习内容：C++基础数据类型、算术运算、整数除法陷阱、强制类型转换、const常量、区分编译error与warning、exe文件占用问题

## 一、环境准备
```powershell
mkdir day4
cd day4
```

仓库根目录：`D:\cpp`，`.gitignore`已配置，自动忽略全部exe文件。

## 二、demo.cpp 基础类型与算术运算

```
#include <iostream>
using namespace std;

int main()
{
    // 整数类型 int
    int a = 10;
    int b = 3;

    // 小数 double
    double pi = 3.1415;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "pi = " << pi << endl;

    // 算术运算 + - * / %
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;   // 重点：整数 / 整数，结果依旧是整数，直接舍弃小数
    cout << "a % b = " << a % b << endl;  // 取余数，只可用于int整数

    return 0;
}
```

> 
> 核心坑点：`10 / 3` 输出为3，不是3.333。整数除法不会四舍五入。

## 三、cast.cpp 强制类型转换

```
#include <iostream>
using namespace std;

int main()
{
    int m = 10;
    int n = 3;

    cout << "m / n (整数除法) = " << m / n << endl;
    // 强制把其中一个操作数转为double，得到小数除法结果
    cout << "(double)m / n = " << (double)m / n << endl;

    return 0;
}
```

> 
> `(double)变量`：临时把变量转换为double类型参与计算，不会改变变量本身存储的值。

## 四、circle.cpp 圆(面积 = \pi \times r^2)计算，const常量

公式：$(面积 = \pi \times r^2) = \pi \times r^2$

```
#include <iostream>
using namespace std;

int main()
{
    const double PI = 3.1415926; // const：常量，值不允许被修改
    double r;
    cout << "请输入圆的半径：";
    cin >> r;

    double area = PI * r * r;
    cout << "圆的\(面积 = \pi \times r^2\)是：" << area << endl;

    return 0;
}
```

知识点：

1. `const`修饰常量，尝试修改常量值会直接编译报错。
2. 控制台中文输出源文件编码必须设置为 **GBK**，否则中文乱码。

### 遇到问题：exe无法删除

现象：修改源码编码后，旧exe删不掉。
原因：程序进程还在运行，Windows文件被进程锁定占用。

解决办法：

1. 关闭VS Code终端（垃圾桶图标）释放文件锁；
2. 新建终端，删除exe：

```
Remove-Item circle.exe
```

备选强制杀进程命令：

```
taskkill /im circle.exe /f
```

3. 保存源码为GBK，重新编译生成新exe。

> 
> 小知识：g++正常情况下会直接覆盖旧exe；只有exe被占用时才会报错权限不足。

## 五、warning.cpp 区分 Error 和 Warning

```
#include <iostream>
using namespace std;

int main()
{
    int num = 3.99; // 小数赋值给int整数
    cout << num << endl;
    return 0;
}
```

- **Error（红色错误）**：编译失败，不生成exe，代码必须修复。
- **Warning（黄色警告）**：编译可以成功生成exe，但代码存在隐患。
本例现象：3.99赋值给int，小数直接截断，输出3，编译器给出警告提醒信息丢失。

## 六、Git 提交（回到仓库根目录 D:\cpp）

```
cd ..
git add .
git commit -m "Day4：数据类型、算术运算、整数除法陷阱、强制类型转换、const常量、编译警告练习"
git push
```

## 七、今日知识点汇总

1. `int` 存整数；`double` 存浮点数（小数）。
2. `%` 取余运算符，**只能用于整数**。
3. 整数除以整数结果还是整数，舍弃小数；想要小数结果需要强制类型转换。
4. `const` 定义只读常量，不允许修改。
5. warning不等于error，警告程序可以运行，但代表代码有风险。
6. exe删不掉绝大多数是进程占用，关闭终端即可释放文件。
7. `.gitignore`自动忽略exe，编译产物不需要上传GitHub。

## 八、踩坑记录

- circle.cpp忘记切换GBK编码导致控制台中文乱码；
- 旧exe被进程锁定无法删除，关闭终端解决。

```
