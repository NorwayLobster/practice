#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int a,b;
	cin>>a>>b;
	cout<<"a:"<<a<<"\n"<<"b:"<<b<<endl;

	a=a^b;
	b=b^a;
	a=a^b;
	cout<<"a:"<<a<<"\n"<<"b:"<<b<<endl;


	return 0;
}