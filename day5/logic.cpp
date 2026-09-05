#include <iostream>
using namespace std;
int main(){
    int year;
    cout<<"请输入年份："<<endl;
    cin>>year;
    if((year%4==0 && year%100!=0)||(year%400==0)){
        cout<<"是闰年"<<endl;
    }
    else{
        cout<<"不是闰年"<<endl;
    }
    return 0;
}