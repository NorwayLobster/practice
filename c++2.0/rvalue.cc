 ///
 /// @file    rvalue.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-07-10 13:50:20
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Stu{
	public:
		Stu(){cout<<"Stu()"<<endl;};
		Stu(int a,int b)
		:_a(b)
		,_b(b)
		{};
		~Stu(){cout<<"~Stu()"<<endl;};
	private:
		int _a;
		int _b;
};
int foo(){
	return 3;
}
int main(){
	int a,b;
//	a+b=10;
//	
	const Stu &s = Stu();
	auto p=&foo();
//	Stu()= s;
//	Stu && s =Stu();
	return 0;
}
