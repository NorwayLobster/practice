//program 20.3.2.cpp auto_ptr示例2
#include <iostream>
#include <memory>
using namespace std;
class A 
{
public:
	int i;
	A(int n):i(n) { };
	~A() { cout << i << " " << "destructed" << endl; }
};
int main() 
{
	auto_ptr<A> ptr1(new A(2)); //A(2)由ptr1托管，
	auto_ptr<A> ptr2(ptr1);     //A(2)交由ptr2托管，ptr1什么都不托管 
	auto_ptr<A> ptr3;
	ptr3 = ptr2;             //A(2)交由ptr3托管， ptr2什么都不托管
	cout << ptr3->i << endl; //输出 2
	A * p = ptr3.release();  // p 指向 A(2)，ptr3解除对A(2)托管  
	ptr1.reset(p);           //ptr1重新托管 A(2)
	cout << ptr1->i << endl; //输出 2
	ptr1.reset(new A(3));    // delete 掉A(2), 托管A(3)，输出 2 destructed
	cout << "end" << endl;
	return 0; //程序结束，ptr1消亡时，会delete 掉A(3)
}

