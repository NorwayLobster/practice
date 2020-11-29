//#include <iostream>
#include <stdio.h>
//using namespace std;

struct A
//class A
{
		int data;
	public:
		int print()
		{
			cout<<"A:data:"<<data<<endl;
			return 0;
		}
};

int main(int argc, char*argv[])
{
	A a;
	a.print();
	//cout<<a.data<<endl;
	return 0;
}
