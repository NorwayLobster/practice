 ///
 /// @file    singletonTemplate.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-25 17:10:26
 ///
 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <pthread.h>
using std::cout;
using std::endl;
using std::vector;
class Student{
public:
	Student(){ cout<<"Student()"<<endl; }
	Student(int x,int y)
	:_age(x)
	,_height(y)
	{
		cout<<"Student(,)"<<endl;
	}

	~Student(){
		cout<<"~Student"<<endl;
	}
//	private:
		int _age;//
		int _height;
};

template<typename T> class Singleton{
	class AutoRelease{
		public:
		AutoRelease(){ cout<<"AutoRelease()"<<endl; }
		~AutoRelease(){ 
			cout<<"~AutoRelease()"<<endl;
			destory();
		}
	};
public:
	template<typename... Args>	static T * getInstance(Args ... args){
		if(NULL==_pInstance){
			//note
			_auto;//未使用，编译器优化，该对象的静态区未构建
			_pInstance=new T(args...);
		}
		return _pInstance;
	}
//	Singleton * getInstance();
	static void destory(){
		if(NULL!=_pInstance)
			delete _pInstance;
	}
private:
		Singleton(){cout<<"Singleton()"<<endl;}
		~Singleton(){cout<<"~Singleton()"<<endl;}
private:
//		static Singleton * _pInstance;
		static T * _pInstance;//note: 此处为静态变量的声明,不是定义,？ ?
		static AutoRelease _auto;//note: 此处为静态变量的声明,不是定义,？

//必须静态，控制执行的次数
		static pthread_once_t once_control;//
};

template<typename T> pthread_once_t Singleton<T>::once_control = PTHREAD_ONCE_INIT;
//lazy mode + pthread_once()
//template<typename T>	T * Singleton<T>::_pInstance=NULL;
//
//eager mode  可以静态成员初始化时，调用getInstance()
template<typename T>	T * Singleton<T>::_pInstance=NULL;
//2. typename? 为什么 : template<typename T> Singleton<T>::AutoRelease Singleton<T>::_atuo;
template<typename T> typename Singleton<T>::AutoRelease Singleton<T>::_auto;//静态成员对象定义//注意不是初始化,但可以在这初始化?

#ifdef __MAIN__
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
#endif 
