//
//  main.cpp
//  Singleton单例模式--类模板
//
//  Created by ChengWang on 3/7/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <string>
#include "singletonVariadicTemplate"
//#include "Singleton.h"

using namespace std;
//v3: 饿汉模式 + 内嵌类和静态对象，实现自动析构 + 多线程不安全
#if 0
template<typename T>
class Singleton{
private:
    Singleton(){cout<<"Singletion()"<<endl;}
    Singleton(const Singleton & );//复制构造,只声明，为定义，可以吗???
    Singleton  & operator=(const Singleton & );//复制运算符重载
    
public:
    ~Singleton(){cout<<"~Singletion()"<<endl;}
    class autoRelease{
    public:
        autoRelease(){ cout<<"autoRelease()"<<endl;}
        ~autoRelease(){ cout<<"~autoRelease()"<<endl; delete __pInstance;}
    };
    static T * getInstance()
    {
        cout<<"getInstance()"<<endl;
        if(__pInstance==NULL)
            __pInstance= new T;
        
        return __pInstance;
    }
    
private:
    static T * __pInstance;
    static autoRelease __auto;
};
template<typename T>
Singleton<T>::autoRelease  __auto;
//Singleton::autoRelease  Singleton::__auto;
template<typename T>
T *  Singleton<T>::__pInstance=NULL;
#endif

class Test
{
private://
    Test(): mstr("abc") { }
    Test& operator = (const Test& t);
    Test(const Test&);
    friend class Singleton<Test> ;  //声明Test的友元为单例类模板
public:
    void Setmstr(string t) { mstr=t; }
    void print()
    {
        cout<<"mstr = "<<mstr<<endl;
        cout<<"this = "<<this<<endl;
    }
private:
    string mstr;
};

#if 0
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    Test *pt1 = Singleton<Test>::getInstance();//模板参数是一个类
    Test *pt2 = Singleton<Test>::getInstance();
//    Test test1;
    pt1->print();
    pt2->print();
    
    pt1->Setmstr("ABCDEFG");
    cout<<endl;
    pt2->print();
    
    return 0;
}
#endif

int main(){
//	Student s(20,180);

//eager mode  也可以main()刚开始就getInstance(), 创建线程之前即可
	Student * pSudent =	Singleton<Student>::getInstance(18,200);
	Student * pSudent1 =	Singleton<Student>::getInstance(23,32);
	vector<int> * pVector=	Singleton<vector<int>>::getInstance();
	vector<int> * pVector1=	Singleton<vector<int>>::getInstance();

	printf("pSudent:%p\n",pSudent);
	printf("pSudent->age:%d\n",pSudent->_age);
	printf("pSudent->_height:%d\n",pSudent->_height);

	printf("pSudent1:%p\n",pSudent1);
	printf("pSudent1->_height:%d\n",pSudent1->_height);
	printf("pSudent1->age:%d\n",pSudent1->_age);

	printf("pVector:%p\n",pVector);
	printf("pVector1:%p\n",pVector1);

//	Singleton<Student>::destory();
	return 0;

}
