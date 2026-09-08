#include <iostream>
using namespace std;
int main(){
    int sum=0;
    for(int i=1; i<=100; i++){
        sum+=i;
    }
    cout<<"一到一百的总和："<<sum<<endl;
    return 0;
}