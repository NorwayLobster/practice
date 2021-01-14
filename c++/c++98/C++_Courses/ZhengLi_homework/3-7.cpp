#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{	
	short int a,b;
	cin>>a>>b;
	short int divide(unsigned int a, unsigned int b);
	cout<<"divide(a,b):"<<divide(a,b)<<endl;
	return 0;
}




short int divide(unsigned int a, unsigned int b){
	if (b==0) return -1;
	return (float)a/b;
}

