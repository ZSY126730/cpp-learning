#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    if(a = 3)   // ?这里是单个=赋值，不是判断相等==
    {
        cout << "a等于3" << endl;
    }
    else
    {
        cout << "a不等于3" << endl;
    }
    return 0;
    
}
