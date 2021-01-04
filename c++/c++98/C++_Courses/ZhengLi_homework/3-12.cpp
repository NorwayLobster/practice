#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
	int a;
	cin>>a;
	int ADD(int a);
	cout<<ADD(a)<<"\n"<<(1+a)*a/2<<endl;
	return 0;
}



int ADD(int n){
	int sum=0;
	if(n==1)
		sum=1;
	else 
		sum=n+ADD(n-1);
	return sum;
}
















