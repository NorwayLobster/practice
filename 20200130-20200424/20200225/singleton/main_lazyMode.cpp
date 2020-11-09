//
//  main.cpp
//  Singletion单例模式--饿汉(懒汉式)
//
//  Created by ChengWang on 3/7/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//
#include <iostream>
using namespace std;
//note:饿汉：懒汉式
#if 0
//v1: 饿汉模式 + 无自动析构，内存泄露 + 多线程不安全
class Singleton{
private:
    Singleton(){cout<<"Singletion()"<<endl;}
    Singleton(const Singleton & );//复制构造
    Singleton  & operator=(const Singleton & );//复制运算符重载
    
public:
    ~Singleton(){cout<<"~Singletion()"<<endl;}
    static Singleton* getInstance()
    {
        cout<<"getInstance()"<<endl;
        if(__pInstance==NULL)
            __pInstance= new Singleton();
        
        return __pInstance;
    }
    
private:
    static Singleton * __pInstance;
};

Singleton * Singleton::__pInstance=NULL;
#endif

#if 0
//v2: 饿汉模式 + 手动析构 + 多线程不安全
class Singleton{
private:
    Singleton(){cout<<"Singletion()"<<endl;}
    Singleton(const Singleton & );//复制构造
    Singleton  & operator=(const Singleton & );//复制运算符重载
    
public:
    ~Singleton(){cout<<"~Singletion()"<<endl;}
    static Singleton* getInstance()
    {
        cout<<"getInstance()"<<endl;
        if(__pInstance==NULL)
            __pInstance= new Singleton();
        
        return __pInstance;
    }
    static void destroy(){ cout<<"destroy()"<<endl;delete __pInstance;}
    
private:
    static Singleton * __pInstance;
};

Singleton * Singleton::__pInstance=NULL;
#endif



//v3: 饿汉模式 + 内嵌类和静态对象，实现自动析构 + 多线程不安全
#if 0
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
    static Singleton* getInstance()
    {
        cout<<"getInstance()"<<endl;
        if(__pInstance==NULL)
            __pInstance= new Singleton();
        
        return __pInstance;
    }
    
private:
    static Singleton * __pInstance;
    static autoRelease __auto;
};

Singleton::autoRelease  __auto;
//Singleton::autoRelease  Singleton::__auto;

Singleton * Singleton::__pInstance=NULL;
#endif




//error：无法编译
//v4: 饿汉模式 + 内嵌类实现自动析构 + pthread_mutex加锁 + 多线程安全
#if 0
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
    static Singleton* getInstance()
    {
        cout<<"getInstance()"<<endl;
        pthread_mutex_lock(&__mutex);
        if(__pInstance==NULL)
            __pInstance= new Singleton();
        pthread_mutex_unlock(&__mutex);
        return __pInstance;
    }
    
private:
    static Singleton * __pInstance;
    static autoRelease __auto;
    static pthread_mutex_t __mutex;
};

Singleton::autoRelease  __auto;
//Singleton::autoRelease  Singleton::__auto;
Singleton * Singleton::__pInstance=NULL;
#endif

//error：无法编译
//v5: 饿汉模式 + 内嵌类实现自动析构 + pthread_mutex加锁+双检锁 +多线程安全
#if 0
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
    static Singleton* getInstance()
    {
        cout<<"getInstance()"<<endl;
        if(__pInstance==NULL){//双检
            pthread_mutex_lock(&__mutex);
            if(__pInstance==NULL)
                __pInstance = new Singleton();
            pthread_mutex_unlock(&__mutex);
        }
        return __pInstance;
    }
private:
    static Singleton * __pInstance;
    static autoRelease __auto;
    static pthread_mutex_t __mutex;
};
Singleton::autoRelease  __auto;
//Singleton::autoRelease  Singleton::__auto;
Singleton * Singleton::__pInstance=NULL;
#endif



//error：无法编译
//v6: 饿汉模式 + 内嵌类实现自动析构 + pthread_mutex加锁+双检锁 +局部变量过渡 +多线程安全 note：__pInstance可能new未完成时，就有值了，防止此时new未完成时__pInstance被使用
#if 0
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
    static Singleton* getInstance()
    {
        cout<<"getInstance()"<<endl;
        if(__pInstance==NULL){
            pthread_mutex_lock(&__mutex);
            if(__pInstance==NULL){
                Singleton * tmp= new Singleton();
                __pInstance=tmp;
            }
            pthread_mutex_unlock(&__mutex);
        }
        return __pInstance;
    }
private:
    static Singleton * __pInstance;
    static autoRelease __auto;
    static pthread_mutex_t __mutex;
};
Singleton::autoRelease  __auto;
//Singleton::autoRelease  Singleton::__auto;
Singleton * Singleton::__pInstance=NULL;
#endif

//待完成
//error：无法编译
//v7: 饿汉模式 + at__exit()加注册函数 替换 内嵌类静态对象，实现自动析构 + pthread_mutex加锁+双检锁 +局部变量过渡 +多线程安全 note：__pInstance可能new未完成时，就有值了，防止此时new未完成时__pInstance被使用
#if 0
class Singleton{
private:
    Singleton(){cout<<"Singletion()"<<endl;}
    Singleton(const Singleton & );//复制构造,只声明，为定义，可以吗???
    Singleton  & operator=(const Singleton & );//复制运算符重载
public:
    ~Singleton(){cout<<"~Singletion()"<<endl;}
    //    class autoRelease{
    //    public:
    //        autoRelease(){ cout<<"autoRelease()"<<endl;}
    //        ~autoRelease(){ cout<<"~autoRelease()"<<endl; delete __pInstance;}
    //    };
    static Singleton* getInstance()
    {
        cout<<"getInstance()"<<endl;
        if(__pInstance==NULL){
            pthread_mutex_lock(&__mutex);
            if(__pInstance==NULL){
                at_exit(&destroy);
                Singleton * tmp= new Singleton();
                __pInstance=tmp;
            }
            pthread_mutex_unlock(&__mutex);
        }
        return __pInstance;
    }
private:
    static Singleton * __pInstance;
    //    static autoRelease __auto;
    static pthread_mutex_t __mutex;
    void * destroy(){ cout<<"destroy()"<<endl;delete __pInstance;}
};
//Singleton::autoRelease  __auto;
//Singleton::autoRelease  Singleton::__auto;
Singleton * Singleton::__pInstance=NULL;
#endif


//待完成
//error：无法编译
//v8: 饿汉模式 + at__exit()加注册函数 替换 内嵌类静态对象，实现自动析构 + pthread_once()(替换 pthread_mutex加锁+双检锁 +局部变量过渡) +多线程安全 note：__pInstance可能new未完成时，就有值了，防止此时new未完成时__pInstance被使用
#if 1
class Singleton{
private:
    Singleton(){cout<<"Singletion()"<<endl;}
    Singleton(const Singleton & );//复制构造,只声明，为定义，可以吗???
    Singleton  & operator=(const Singleton & );//复制运算符重载
public:
    ~Singleton(){cout<<"~Singletion()"<<endl;}
    //    class autoRelease{
    //    public:
    //        autoRelease(){ cout<<"autoRelease()"<<endl;}
    //        ~autoRelease(){ cout<<"~autoRelease()"<<endl; delete __pInstance;}
    //    };
    static Singleton* getInstance()
    {
        cout<<"getInstance()"<<endl;
        if(__pInstance==NULL){
            pthread_mutex_lock(&__mutex);
            if(__pInstance==NULL){
                at_exit(&destroy);
                Singleton * tmp= new Singleton();
                __pInstance=tmp;
            }
            pthread_mutex_unlock(&__mutex);
        }
        return __pInstance;
    }
private:
    static Singleton * __pInstance;
    //    static autoRelease __auto;
    static pthread_mutex_t __mutex;
    void * destroy(){ cout<<"destroy()"<<endl;delete __pInstance;}
};
//Singleton::autoRelease  __auto;
//Singleton::autoRelease  Singleton::__auto;
Singleton * Singleton::__pInstance=NULL;
#endif




int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, spellCorrection!\n";
    Singleton * p=Singleton::getInstance();
    Singleton * p1=Singleton::getInstance();
    printf("%p\n",p);
    printf("%p\n",p1);
    //    Singleton::destroy();//不能定义成成员函数吗？必须静态函数？
    //    p1-->destroy();
    return 0;
}
