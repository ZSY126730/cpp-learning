#include <iostream>
using namespace std;
int main()
{
    int arr[3][2]={{11,22},{33,44},{55,66}};

    cout<<arr[0][0]<<endl;
    cout<<arr[1][1]<<endl;

    arr[2][0]=99;
    cout<<arr[2][0]<<endl;
    return 0;
}
