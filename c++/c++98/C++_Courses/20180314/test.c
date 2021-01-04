#include <stdio.h>

struct A
{
	private:
		int data;
		int print()
		{
			cout<<"A:data:"<<data<<endl;
			return 0;
		}
};

int main(int argc, char*argv[])
{
	struct A a;
	a.print();
	//cout<<a.data<<endl;
	return 0;
}
