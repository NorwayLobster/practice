 ///
 /// @file    memberFunctionAccessOperator.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-24 23:11:18
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//we have a class
struct X
{
   void f() {cout<<"f()"<<endl;}
  void g() {cout<<"g()"<<endl;}
};
       
int main(){
       typedef void (X::*pointer)();
       //ok, let's take a pointer and assign f to it.
       pointer somePointer = &X::f;
       pointer somePointer1 = &X::g;

	   //????
		cout<<"pointer:"<<somePointer<<endl;
		cout<<"pointer1:"<<somePointer1<<endl;
		cout<<"pointer1:"<<&X::f<<endl;
		printf("%\n",&X::f);
       //now I want to call somePointer. But for that, I need an object
       X x;
       //now I call the member function on x like this
       (x.*somePointer)(); //will call x.f()
       //now, suppose x is not an object but a pointer to object
       X* px = new X;
       //I want to call the memfun pointer on px. I use ->*
       (px ->* somePointer1)(); //will call px->f();
//       (px ->* somePointer)(); //will call px->f();
	   return 0;
}


