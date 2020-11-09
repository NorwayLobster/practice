 ///
 /// @file    memberFunctionAsCallback.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-09-25 19:35:16
 ///
 
#include <iostream>
#include <functional>
#include <memory>
using namespace std;

using Callback=std::function<void(int,int)>;
class Stu:public std::enable_shared_from_this<Stu>{
public:
	Stu(int x=0,int y=0)
		:_x(x)
		,_y(y)
	{cout<<"Stu()"<<endl;}
	~Stu(){cout<<"~Stu()"<<endl;}
//	void f(){ func(print); } //wrong
//	成员函数做回调函数
//	way1:
//	void f(){ func([this](int a, int b){this->print(a,b);}); }
//	way3:
	void f(){ func([self=shared_from_this()](int a, int b){self->print(a,b);}); }
//	way2:
//	void f(){ func(std::bind(&Stu::print,this,std::placeholders::_1,std::placeholders::_2)); }
private:
	void print(int a,int b){cout<<"Stu func():\na:"<<a<<",b:"<<b<<endl;}
	void func(Callback cb){
		cb(_x,_y);
	}
private:
	int _x;
	int _y;
};

int main(){
#if 1
//	std::shared_ptr<Stu> pS=std::make_shared<Stu>(10,12);
	std::shared_ptr<Stu> pS(new Stu(10,12));
	pS->f();
#endif
#if 0
	Stu stu(10,12);
	stu.f();
#endif

	return 0;
}
