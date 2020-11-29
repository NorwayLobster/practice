//program 12.1.3.4.cpp  复制构造函数用于函数返回对象
#include <iostream>
using namespace std;

class A 
{
   public:
   int v;
   A(int n) { v = n; };
   A( const A & a) { 
  	  v = a.v;
   	  cout << "Copy constructor called" <<endl;
   }		
};
A Func()
{
   A a(4);
   return a; 		   
}
int main(){
	cout << Func().v << endl;
	return 0;
}

