//program 12.9.2.1.cpp  this指针存在的证明
#include <iostream>
using namespace std;
class A
{ 	
		 int i;
   public: 
   	 void Hello() { cout << "hello" << endl; } 
};
int main() 
{ 
  	A * p = NULL;
  	p->Hello();
}
