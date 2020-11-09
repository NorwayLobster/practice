 ///
 /// @file    sigleton.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-23 18:46:20
 ///
 
#include <iostream>
#include <cstdio>
#include <cstdlib>
using std::cout;
using std::endl;

class Sigleton{
public:
//2.自动析构
class autoRelease{
	public:
		autoRelease();
		~autoRelease();
};

		static Sigleton * getInstance()
		{
//4.多线程安全 lazy mode
//			mutext lock here
			if(NULL==_pInstance){
				_pInstance=new Sigleton;
//				Sigleton::_pInstance=new Sigleton;
				printf("pSigleton:%p\n",_pInstance);
			}
//			mutext unlock here
			return _pInstance;
//			return Sigleton::_pInstance;
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
	static	autoRelease  _ar;
};

Sigleton::autoRelease _ar;//init
//4.多线程安全 lazy mode + mutex
//Sigleton * Sigleton::_pInstance=NULL;
//5.多线程安全 eager mode
Sigleton * Sigleton::_pInstance=Sigleton::getInstance();
Sigleton::autoRelease::autoRelease(){
	cout<<"autoRelease ctor"<<endl;
} 

Sigleton::autoRelease::~autoRelease(){
	cout<<"autoRelease destructor"<<endl;
	Sigleton::destroyInstance();
} 


int main(){
	

//		Sigleton * pSigleton1=new Sigleton;
		Sigleton * pSigleton=Sigleton::getInstance();
		Sigleton * pSigleton1=Sigleton::getInstance();
		//cout<<"pSigleton:"<<pSigleton<<endl;
	
		printf("pSigleton:%p\n",pSigleton);
		printf("pSigleton1:%p\n",pSigleton1);
//1.手动析构
//		pSigleton->destroyInstance();
//		pSigleton1->destroyInstance();
		return 0;
}
