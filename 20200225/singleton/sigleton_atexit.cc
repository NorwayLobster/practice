 ///
 /// @file    sigleton.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-23 18:46:20
 ///
 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <pthread.h>
using std::cout;
using std::endl;

class Sigleton{
public:
		static Sigleton * getInstance()
		{
//3.pthread_once():多线程安全
//error:once_control定义静态成员			pthread_once_t once_control = PTHREAD_ONCE_INIT;
			pthread_once(&once_control ,Sigleton::createInstance);
			
			return _pInstance;
//			return Sigleton::_pInstance;
		}
		static void createInstance(){
				_pInstance=new Sigleton;
//2.atexit():自动析构
				atexit(Sigleton::destroyInstance);
				printf("createInstance(), pSigleton1:%p\n",_pInstance);
//				Sigleton::_pInstance=new Sigleton;
		}

		static void  destroyInstance(){
			printf("destroyInstance\n");
			if(NULL!=_pInstance){
				cout<<"in if destroyInstance()"<<endl;
				Sigleton *pTmp=_pInstance;
				_pInstance=NULL;
				delete pTmp;
//				delete _pInstance;
			}
		}

private:
		Sigleton(){
			cout<<"Sigleton()"<<endl;
		}
		~Sigleton(){
//			cout<<"~Sigleton()"<<endl;
			cout<<"~Sigleton()"<<endl;
		}
private:
	static	Sigleton * _pInstance;
    static pthread_once_t once_control;
};

Sigleton * Sigleton::_pInstance=NULL;

pthread_once_t Sigleton::once_control = PTHREAD_ONCE_INIT;

int main(){

//		pthread_once_t once_control = PTHREAD_ONCE_INIT;
//		typedef void(* FuncType)();
//		pthread_once(&once_control ,(FuncType)Sigleton::getInstance);

//		Sigleton * pSigleton1=new Sigleton;
		Sigleton * pSigleton=Sigleton::getInstance();
		Sigleton * pSigleton1=Sigleton::getInstance();
		//cout<<"pSigleton:"<<pSigleton<<endl;
	
		printf("pSigleton:%p\n",pSigleton);
		printf("pSigleton1:%p\n",pSigleton1);
		return 0;
}
