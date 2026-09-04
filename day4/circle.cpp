#include <iostream>
using namespace std;
int main(){
    const double PI=3.1415926;
    double r;
    cout<<"请输入圆的半径："<<endl;
    cin>>r;
    double area=PI*r*r;
    cout<<"圆的面积是："<<area<<endl;
    return 0; 
    
}