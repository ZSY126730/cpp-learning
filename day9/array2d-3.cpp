#include <windows.h>
#include <iostream>
using namespace std;


int main()
{
    int arr[2][3];
    cout<<"请输入二行三列，一共六个整数："<<endl;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"你输入的矩阵："<<endl;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}