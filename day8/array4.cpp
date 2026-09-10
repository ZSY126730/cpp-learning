#include <iostream>
using namespace std;
int main(){
    int score[5]= {99,79,48,88,24};
    int sum=0;
    for(int i=0;i<5;i++){
        sum+=score[i];
    }
    double avg=sum/5.0;
    cout<<"总分："<<sum<<"\n";
    cout<<"平均分："<<avg<<"\n";
    return 0;
}