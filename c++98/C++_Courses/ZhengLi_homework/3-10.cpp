#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{

	int mostFactor(int a, int b);
	int mostMultiplication(int a, int b);
	int a,b; 

	// cin>>a>>b;
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{ 
	cout<<i<<setw(4)<<j<<setw(8)<<mostFactor(i,j)<<setw(8)<<mostMultiplication(i,j)<<endl;

		}
	cout<<endl;

	}
	// cout<<i<<setw(4)<<j<<setw(8)<<mostFactor(a,b)<<setw(8)<<mostMultiplication(a,b)<<endl;


	return 0;
}



int mostFactor(int a, int b){


	int k, mostFactor = 1;

	if(a>b)
	{
		k= b/2;
		if(a%b==0)
			return  b;
	}
	else {
		k= a/2;
		if (b%a==0)
			return a;
	}

	for (int i = 2; i <= k; ++i)
	{
		if (a%i==0 && b%i==0)
		{	
			mostFactor=i;
		}
	}
	return mostFactor;
}



int mostMultiplication(int a, int b){


	return a*b/mostFactor(a,b);
}

















