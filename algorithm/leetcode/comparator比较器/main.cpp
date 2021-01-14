//
//  main.cpp
//  comparator比较器
//
//  Created by ChengWang on 3/6/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
//优先级定义：年龄age小的优先，
class Student {
public:
    Student(){}
    Student(string name, int id, int age):
    __name(name),
    __id(id),
    __age(age)
    {
//        this.name = name;
//        this.id = id;
//        this.age = age;
    }
    
    Student(const Student & s)://const 必须有 为了匿名对象的绑定
    __name(s.__name),
    __id(s.__id),
    __age(s.__age)
    {
        
    }
#if 1
    Student & operator=(const Student & s)
    {
        if(this!=&s)//比较指针，check是否为同一个对象
        {
            __name=s.__name;
            __id=s.__id;
            __age=s.__age;
        }
        return *this;
    }
    
    bool operator<(Student &s2) const { return __age<s2.__age; }
//    bool operator<(Student &s2) const { return __age<s2.__age; }
#endif

public:
    string __name;
    int __id;
    int __age;
};

void printStudents(Student & st)
{
//    for(auto & s: st_s)
    cout<<"name:"<<st.__name<<','<<"id:"<<st.__id<<','<<"age:"<<st.__age<<endl;
}

int printStudents(Student * st, int size)
{
    for(int i=0;i<size;++i)
        cout<<"name:"<<st[i].__name<<','<<"id:"<<st[i].__id<<','<<"age:"<<st[i].__age<<endl;
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, comparator!\n";
//    Student *student1 = new Student("A", 1, 23);
    Student student1("A", 1, 23);
    Student student2("B", 2, 21);
    Student student3("C", 3, 22);
    Student student4(student1);
    Student student5 = student1;//存在有default assignment operator
    
    //动态申请结构体数组，并初始化
    Student students[3] = { student3, student2, student1 };
//    Student * pstudents = new Student[]{{"A", 1, 23}, {"A", 1, 23}, {"A", 1, 23}};//error
//    Student * pstudents1 = new Student[3]();
//        Student * pstudents = new Student[]{ {student3}, {student2}, {student1} }; //error
//    double * pdouble= new double[]{ 1.0,2,3};//error
//    double* p = new double[]{1,2,3};//error
//    printStudents(pstudents[0]);
//     int (* p)() = new (int (*[10])());//error
    printStudents(student2);
    printStudents(student3);
    printStudents(student4);
    printStudents(student5);
    printStudents(students[0]);
    printStudents(students[2]);
    cout<<endl;
    printStudents(students, 3);
    vector<Student> v;
    v.push_back(student1);
    v.push_back(student2);
    v.push_back(student3);
  //
//    比较器：
//    bool cmp(Student  s1, Student s2);
//        bool cmp(Student  s1, Student s2);
    struct AgeDescendingComparator{
//        struct cmp;//该比较器前向声明，错误？？？？？？？？？？？？？？？？？？？
        bool operator()(const Student & s1, const Student &s2) const
        {
//            当返回true的情况下：s1先于s2出现
            return s1.__age<s2.__age;// 当lhs优先级小于 rhs时，return true;
        }
    };

//当返回true的情况下：s1先于s2出现
//优先级大的在前面:即优先级降序排列 greater<>: 如果，lhs优先级 大于 或者说 优先于 rhs，return true；否则，return false
//优先级小的放前面:即优先级升序排列 less<>: 如果，lhs优先级 小于 或者说 落后于 rhs，return true；否则，return false
//此处，优先级定义：年龄age大的优先级高，
struct ComparatorLess{//
        bool operator()(const Student & s1, const Student &s2) const
        {
            if(s1.__age<s2.__age){//当s1.__age值大于s2.__age值时，表示s1的优先级小于s2;
                return true;
            }else if(s1.__age>s2.__age){//当s1.__age值小于于s2.__age值时，表示s1的优先级大于s2;
                return false;
            }else{//相等时关系到 稳定性
                return true;//????
            }
            
            
        }
};
struct ComparatorGreater{//
        bool operator()(const Student & s1, const Student &s2) const
        {
            if(s1.__age>s2.__age){//当s1.__age值大于s2.__age值时，表示s1的优先级小于s2;
                return true;
            }else if(s1.__age<s2.__age){//当s1.__age值小于于s2.__age值时，表示s1的优先级大于s2;
                return false;
            }else{//相等时关系到 稳定性
                return true;//????
            }
            
            
        }
};
    
//    less<>模板： return left-right：小在前，从小到大
    struct AgeAscendingComparator{
        //        struct cmp;//该比较器前向声明，错误？？？？？？？？？？？？？？？？？？？
        bool operator()(const Student & s1, const Student &s2) const
        {
            //            当返回true的情况下：s1先于s2出现
            if(s1.__age<s2.__age)
                return true;
            else
                return false;
//            return s1.__age<s2.__age;
        }
        
    };
    cout<<endl;
    cout<<endl;
    cout<<endl;
  //less<>模板不能用于自定义类型  sort(v.begin(),v.end(),less<Student>());//
//    sort(v.begin(),v.end(),AgeAscendingComparator());
    for(auto &a:v)
        printStudents(a);
    cout<<endl;
    cout<<endl;
    cout<<endl;
//    sort(v.begin(),v.end(),ComparatorLess());//优先级 渐升
    sort(v.begin(),v.end(),ComparatorGreater());//优先级 渐降
//    sort(v.begin(),v.end(),AgeDescendingComparator());
    for(auto index=0;index<v.size();++index)
        printStudents(v[index]);
//    priority_queue<Student> pq;
//    priority_queue<Student,vector<Student>, cmp> pq;
//    priority_queue<Student> pq(v.begin(),v.end());
    priority_queue<Student,vector<Student>, ComparatorLess> pq(v.begin(),v.end());
//    priority_queue<Student,vector<Student>, AgeDescendingComparator> pq(v.begin(),v.end());
    
//    pq.push(student1);
//    pq.push(student2);
//    pq.push(student3);
    cout<<endl;
    cout<<endl;
    cout<<endl;
//    Student e1= pq.top(;
//    printStudents(e1);
    
#if 1
   int n=3;
    cout<<"PQ"<<endl;
    for(int i=0;i<n;++i)
    {
        Student e1= pq.top();
        printStudents(e1);
        //error: printStudents(pq.top());？？？？？？？？？？？？？？？？？？？？？？？
        pq.pop();
    }
#endif
    
    return 0;
}

//bool cmp(Student  s1, Student s2){
//    return s1.__age<s2.__age;
//}
//
