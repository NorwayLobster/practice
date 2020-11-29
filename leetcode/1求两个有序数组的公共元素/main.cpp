//
//  main.cpp
//  1求两个有序数组的公共元素
//
//  Created by ChengWang on 1/23/20.
//  Copyright © 2020 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
void printVector(vector<int> &v);


using namespace np1;
class np1::np2::Stu;
class cmpStu{
public:
    bool operator () ( const np1::np2::Stu &a,const np1::np2::Stu &b){
        return a.age>b.age;
    }
};

namespace np1 {
namespace np2 {
class Stu{
public:
//    结论：C++中类成员变量的初始化顺序与其在类中的声明顺序是有关的，而与其在初始化列表中的顺序无关
    Stu()=default;
    Stu(int _age, int _grade, double _height, double _salary,const string &_name):
    age(_age),grade(_grade),height(_height),salary(_salary),name(_name)
    {printf("Stu()\n");};
    
    ~Stu()=default;
    friend class cmpStu;
    friend bool cmpStu::operator () ( const Stu &a,const Stu &b);
//    friend bool cmpStu::operator () ( const np1::np2::Stu &a,const np1::np2::Stu &b);
    
protected:
    int age;
private:
    int grade;
    double height;
    double salary;
    string name;
};
}
}

np1::np2::Stu s;
np1::np2::Stu s1(29,1,186,25,"chengwang");



struct cmp{
    bool operator () ( const int &a,const int &b){
        return a>b;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Student s1;
    s1.age=10;
    s1.grade=10;
    s1.name="chengwang";
    pStuent p1= &s1;
    s1.s=p1;
    
    std::cout << "Hello, World!\n";
    vector<int> v1={1,2,34,56,12312,33,4,43,23};
    vector<int> v2={1,2,3,4,5,6,12,31,2,33,4,43,23};
    printVector(v1);
    printVector(v2);
    sort(v1.begin(),v1.end(),greater<int>());
    sort(v2.begin(),v2.end(),cmp());
//    priority_queue<>(<#const priority_queue<_Tp, _Container, _Compare> &__q#>)
//    sort(v1.begin(),v1.end(),greater<int>());
//    sort(v1.begin(),v1.end(),less<int>());
//    sort(v2.begin(),v2.end());
    printVector(v1);
    printVector(v2);
    
    
    
    
    return 0;
}
void printVector(vector<int> &v){
    for(auto ele:v)
        printf("%d_",ele);
    printf("\n");
}
