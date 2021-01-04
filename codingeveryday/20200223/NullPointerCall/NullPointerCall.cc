 ///
 /// @file    NullPointerCall.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-23 17:08:34
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class NullPointerCall{
	public:
		NullPointerCall():
		_x(0)
		{
			cout<<"default ctor"<<endl;
		}
//		explicit//防止隐式转换
		NullPointerCall(int x):
		_x(x)
		{
			cout<<"ctor"<<endl;
		}
		void print1(){
			cout<<"void print1()"<<endl;
		}
#if 1
		void print2(int x) const {
			cout<<"void print2() const"<<x<<endl;
		}
#endif
		void print2(int x) {
			cout<<"void print2()"<<x<<endl;
		}
		static void print3(){
			cout<<"void print3()"<<_y<<endl;
		}

		void print4(){//报错，this->_x
			cout<<"void print4()"<<endl;
			cout<<_x<<endl;
		}

		~NullPointerCall(){
			cout<<"~destructor"<<endl;
		}

	private:
		int _x;
		static int _y;

};

int NullPointerCall::_y=10;
int main(){
//1.对象调用 细节
	NullPointerCall *p=NULL;
	p->print1();
	p->print2(-10);
	p->print3();
//error:	p->print4();

	NullPointerCall const p1;
	p1.print2(-11);

	cout<<endl;
//2.对象数组
	NullPointerCall p2[5];
	cout<<endl;
	cout<<endl;
	NullPointerCall p3[5]={ NullPointerCall(1), NullPointerCall(12)};

//3.explicit
	cout<<endl;
	NullPointerCall p4=1;
//4.堆
	cout<<endl;
	NullPointerCall* p5 =new NullPointerCall[5];
	delete [] p5;
	p5=NULL;
	return 0;
}
