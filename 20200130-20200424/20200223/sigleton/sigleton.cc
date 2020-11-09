 ///
 /// @file    sigleton.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-23 18:46:20
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class insideClass{
	
};

class Sigleton{
public:

		static Sigleton * getInstance()
		{
			if(NULL==_pInstance){
				_pInstance=new Sigleton;
//				Sigleton::_pInstance=new Sigleton;
				printf("pSigleton1:%p\n",_pInstance);
			}
			return _pInstance;
//			return Sigleton::_pInstance;
		}
		void  destroyInstance(){
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
		Sigleton(){//防止类外call ctor
			cout<<"Sigleton()"<<endl;
		}
		~Sigleton(){
//			cout<<"~Sigleton()"<<endl;
			cout<<"~Sigleton()"<<endl;
		}
private:
	static	Sigleton * _pInstance;
};

Sigleton * Sigleton::_pInstance=NULL;

int main(){
//		Sigleton s;//类外call ctor
//		Sigleton * pSigleton1=new Sigleton;//类外call ctor
		Sigleton * pSigleton=Sigleton::getInstance();
		Sigleton * pSigleton1=Sigleton::getInstance();
		//cout<<"pSigleton:"<<pSigleton<<endl;
	
		printf("pSigleton:%p\n",pSigleton);
		printf("pSigleton1:%p\n",pSigleton1);
		pSigleton->destroyInstance();
		pSigleton1->destroyInstance();
		return 0;
}
