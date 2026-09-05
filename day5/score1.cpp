#include <iostream>
using namespace std;
int main(){
    int score;
    cout<<"请输入分数："<<endl;
    cin >>score;
    if(score>=60){
        cout <<"成绩及格"<<endl;
    }
    else{
        cout<<"成绩不及格"<<endl;
    }

    return 0;


}