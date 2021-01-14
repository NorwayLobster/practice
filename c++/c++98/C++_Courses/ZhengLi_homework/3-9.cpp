#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	bool primeJudge(double);
	double a; 

	// cin>>a;
	for (double i = 1; i < 100; ++i)
	{	a=i;
		if (primeJudge(i))
		cout<<i<<":yes";
	else cout<<a<<":no";
	cout<<endl;

	}

	cout<<endl;

	return 0;
}



bool primeJudge(double b){
	int a=int(b);
	// if (b==a || a<=0)
	// 	return false;

	if(a==1 || a==2)
		return true;

	int k= sqrt(a);
	// bool flag=false;
	for (int i = 2; i <= k; ++i)
	{
		if (a%i==0)
		{	
			// flag=true;
			return false;
		}
	}
	// if (!flag)
	return true;
}
