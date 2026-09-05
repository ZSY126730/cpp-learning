
# Day5 学习笔记
> 日期：2026?09?05
> 工作目录：`D:\cpp\day5`
> 学习内容：if?else条件分支、关系运算符、逻辑运算符、多分支if?else if?else、闰年判断、`=`赋值与`==`相等笔误坑、编译警告参数 `-Wall`
> .gitignore 已配置，自动忽略exe文件

## 一、环境准备
```powershell
mkdir day5
cd day5
```

## 二、练习1 score1.cpp 基础if?else 双分支

功能：输入分数，判断是否及格

```
#include <iostream>
using namespace std;

int main()
{
    int score;
    cout << "请输入考试分数：";
    cin >> score;

    if(score >= 60)
    {
        cout << "成绩及格" << endl;
    }
    else
    {
        cout << "成绩不及格" << endl;
    }
    return 0;
}
```

编译运行（开启警告）

```
g++ -Wall score1.cpp -o score1.exe
.\score1.exe
```

测试用例：85、59、60

### ?踩坑记录

> 
> 错误：`cin >> score;`写在cout提示前面
> 现象：运行程序光标闪烁，没有任何文字输出，程序在等待输入，看起来像卡死。
> 原理：代码从上往下顺序执行，**必须先cout打印提示，再cin接收输入**。

### 关系运算符

| 符号 | 含义 |
| --- | --- |
| `>` | 大于 |
| `<` | 小于 |
| `>=` | 大于等于 |
| `<=` | 小于等于 |
| `==` | 判断相等（两个等号） |
| `!=` | 不等于 |

> 
> ??大坑：判断相等用 `==`；单个`=`是赋值操作。

## 三、练习2 score2.cpp 多分支 if?else if?else

分数等级

- ≥90：优秀
- 80~89：良好
- 70~79：中等
- 60~69：及格
- ＜60：不及格

```
#include <iostream>
using namespace std;

int main()
{
    int score;
    cout << "请输入考试分数：";
    cin >> score;

    if(score >= 90)
    {
        cout << "优秀" << endl;
    }
    else if(score >= 80)
    {
        cout << "良好" << endl;
    }
    else if(score >= 70)
    {
        cout << "中等" << endl;
    }
    else if(score >= 60)
    {
        cout << "及格" << endl;
    }
    else
    {
        cout << "不及格" << endl;
    }
    return 0;
}
```

编译运行

```
g++ -Wall score2.cpp -o score2.exe
.\score2.exe
```

测试：95、82、77、63、45

> 
> 执行逻辑：从上到下依次判断，一旦某个条件成立，执行对应代码，后面所有分支不再判断。

## 四、练习3 logic.cpp 逻辑运算符 && || !，闰年判断

- `&&` 并且：两边条件全部成立才为真
- `||` 或者：任意一个条件成立即为真
- `!` 取反：条件真假翻转

闰年规则：

1. 能被4整除 **并且** 不能被100整除
2. **或者** 能被400整除

```
#include <iostream>
using namespace std;

int main()
{
    int year;
    cout << "请输入年份：";
    cin >> year;

    if( (year%4 == 0 && year%100 !=0 ) || (year%400 ==0) )
    {
        cout << year << " 是闰年" << endl;
    }
    else
    {
        cout << year << " 不是闰年" << endl;
    }
    return 0;
}
```

编译运行

```
g++ -Wall logic.cpp -o logic.exe
.\logic.exe
```

测试用例：2024（闰年）、2000（闰年）、1900（非闰年）、2025（非闰年）

> 
> 小技巧：复杂条件多加括号，提升可读性，避免优先级出错。

## 五、练习4 bug?if.cpp 高危笔误：if内部写赋值`=`

```
#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    if(a = 3)   // ?这里是赋值=，不是判断相等==
    {
        cout << "a等于3" << endl;
    }
    else
    {
        cout << "a不等于3" << endl;
    }
    return 0;
}
```

### 关键知识点：编译参数 `-Wall`

- 直接 `g++ bug-if.cpp -o bug-if.exe`：编译器静默编译，**不输出警告**，隐患看不见，程序运行输出错误结果。
- `g++ -Wall bug-if.cpp -o bug-if.exe`：开启警告检测，输出提示：
`warning: suggest parentheses around assignment used as truth value [-Wparentheses]`

> 
> 现象：`a=5`，但是程序输出`a等于3`
> 原理：`a = 3`把3赋值给a；非0数字在if条件中视为true，条件直接成立。
> 本意应该写：`if(a == 3)`

运行

```
.\bug-if.exe
```

## 六、编译报错复盘：undefined reference to WinMain

触发原因：

1. `main`拼写错误（Mian / mian / MAIN）
2. 文件修改完成**没有Ctrl+S保存**，编译的还是旧残缺文件
解决：修正`int main()`，保存文件，重新编译。

## 七、Git提交（退回仓库根目录 D:\cpp）

```
cd ..
git add .
git commit -m "Day5：if?else分支，多分支判断，逻辑运算符&& || !，闰年判断，=与==笔误坑练习，使用?Wall开启编译警告"
git push
```

## 今日总结

1. 代码从上向下顺序执行，cin输入前先cout打印提示文字。
2. 关系运算符：判断相等必须使用 `==`，区分赋值`=`。
3. `&&`并且、`||`或者，复杂逻辑条件建议加括号。
4. if?else if?else从上往下匹配，匹配成功就不再执行后续分支。
5. **强烈建议每次编译带上 `-Wall`**，主动捕获隐藏风险警告。
6. Warning警告 ≠ Error错误：警告可以生成exe，代表代码有隐患；Error直接编译失败。

## 今日踩坑记录

1. cout与cin书写顺序颠倒，程序等待输入但无提示，误以为卡死。
2. 文件修改后忘记保存，出现WinMain链接报错。
3. g++默认关闭警告，赋值笔误不会提醒，必须加 `-Wall` 参数。

```