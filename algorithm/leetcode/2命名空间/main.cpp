//
//  main.cpp
//  2命名空间
//
//  Created by ChengWang on 1/23/20.
//  Copyright © 2020 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>

typedef struct Student_tag{
    int age;
    Student_tag *  s;
    string name;
    int grade;
} Student, * pStuent;

typedef struct Node_tag{
    int val;
    Node_tag*next;
} Node,*pNode;
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
    std::cout << "Hello, World!\n";
    return 0;
}

