#include <iostream>
using namespace std;
int main(){
    int num;
    cout<<"请输入数字，输入0结束程序："<<endl;
    cin>>num;
    while(num!=0){
        cout<<"你输入的数字是："<<num<<endl;
        cin>>num;
    }
    cout<<"程序结束"<<endl;
    return 0;
}