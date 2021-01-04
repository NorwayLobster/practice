 ///
 /// @file    namespace.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-22 23:11:23
 ///
 
#include <iostream>
#include <cstdio>//c的函数或变量都在匿名空间里
void display(){//匿名空间
	using std::cout;//编译声明
	using std::endl;
	cout<<"::display()"<<endl;
}
namespace B{
	void print(int number);//声明
}
namespace A{
	int number=100;
	using std::cout;//编译声明
	using std::endl;
	void display(){
		cout<<"A::display()"<<endl;
		int number=10;
		B::print(number);
	}
}//end of namespace A

namespace B{
	using std::cout;//编译声明
	using std::endl;
	void display(){
		cout<<"B::display()"<<endl;
	}
	
	void print(int number){
		cout<<"in B 形参number"<<number<<endl;
	}
}//end of namespace B
int number=20000;
int main(){
	using std::cout;//编译声明
	using std::endl;
	int number=1000;
	cout<<"hello world"<<endl;
	A::display();
	B::display();
	::display();
	cout<<number<<endl;
	cout<<"number"<<number<<endl;
	cout<<"::number"<<::number<<endl;
	cout<<"A::number"<<A::number<<endl;

	::printf("::printf()\n");
	return 0;
}
