//program 20.6.1.1.cpp shared_ptr
#include <memory>
#include <iostream>
using namespace std;
class A
{    
 public:
	 int n;
	 A(int v):n(v){ } 
	 ~A() { cout << n << " destructor" << endl; }
};
int main()
{
     shared_ptr<A> sp1(new A(2));
	shared_ptr<A> sp2(sp1);
	cout << sp1->n  << "," << sp2->n << endl; 
} 

