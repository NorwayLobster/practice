#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	double x;
	cin>>n>>x;
	double p(int n, double x);
	cout<<p(n, x)<<endl;
	return 0;
}


 
double p(int n, double x){
	double sum=0;
	if(n==0)
		sum=0;
	else if(n==1)
		sum=x;
	else 
		sum=((2*n-1)*x*p(n-1, x)+(n-1)*p(n-2, x))/n;

	return sum;
}
















