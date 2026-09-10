#include <iostream>
using namespace std;
int main(){
    int arr[5]={};
    cout<<"请输入5个整数:\n";
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
    cout<<"您输入的整数是：\n";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}