 ///
 /// @file    memberFunctionTemplate.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-25 18:29:49
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Test{
	public:
		Test(){ cout<<"Test()"<<endl; }
		Test(int x,int y)
		:_x(x)
		,_y(y)
		{ cout<<"Test()"<<endl; }
		~Test(){ cout<<"~Test()"<<endl; }
		//void print(int x, double y, float z){
		template<typename T1,typename T2,typename T3> 
			void print(T1 x, T2 y, T3 z){
			cout<<"x:"<<x<<",y:"<<y<<",z:"<<z<<endl;
		}
	private:
		int _x;
		int _y;
};

int main(){
	Test t(1,2);
	t.print(0,2.23,3.2);
	t.print<int,double,float>(0,2,3);//显示
	return 0;
}
