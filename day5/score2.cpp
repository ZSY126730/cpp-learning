#include <iostream>
using namespace std;
int main(){
    int score;
    cout<<"请输入考试分数："<<endl;
    cin>>score;
    if(score>=90){
        cout<<"成绩优秀"<<endl;
    }
    else if(score>=80){
        cout<<"成绩良好"<<endl;
    }
    else if(score>=70){
        cout<<"成绩中等"<<endl;
    }
    else if(score>=60){
        cout<<"成绩及格"<<endl;
    }
    else{
        cout<<"成绩不及格"<<endl;
    }
    return 0;




}