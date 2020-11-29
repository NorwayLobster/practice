//program 20.4.5.cpp  bad_cast异常
#include <iostream>
#include <stdexcept>
using namespace std;
class Base 
{ 
	virtual void func(){} 
};
class Derived : public Base 
{ 
public:
	void Print() { }  	  
};
void PrintObj( Base & b)
{
	  try  {
	  	Derived & rd = dynamic_cast<Derived&>(b);
 	    //此转换若不安全，会抛出bad_cast异常
 	     rd.Print();
	  }
	  catch (bad_cast& e)	  {
	     cerr << e.what() << endl;
	  }
}
int main () 
{
  	Base b;	 
  	PrintObj(b);
  	return 0;
}

