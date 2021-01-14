#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	//wrong
	// double x,y;
	cout<<"plase input a int base number:";
	int x;
	cin>>x;
	cout<<"plase input a double base number:";
	double y;
	cin>>y;
	cout<<"to what power:";
	cin>>n;

	int getPower(int x, int y);
	double getPower(double x, int y);
	if(n<0)
	{
		cout<<"a minus/negative int power:"<<1.0/getPower(x, -n)<<endl;
        cout<<"a negative int power in strong type cast way:"<<getPower((double)x, n)<<endl;	
    }
	else 
		cout<<"a positive int power:"<<getPower(x, n)<<endl;
	cout<<pow(x, n)<<endl;
	cout<<endl;
	cout<<"double:"<<getPower(y, n)<<endl;
	cout<<pow(y, n)<<endl;
	return 0;
}


 
double getPower(double x, int n){
	// double multiplication=1;不需要,而且是累赘;直接返回 表达是即可,简洁,快速,明了,方便,高效;
	if (n<0)
		return 1/getPower(x, abs(n));

	else if (n==0)
		return 1;
	else if(n==1)
		return x;

	else 
		return x*getPower(x,n-1);

	// return multiplication;
}


int getPower(int x, int n){
	// double multiplication=1;
	if (n<0)
		return 0;

	else if(n==0)
		return 1;
	else if(n==1)
		return x;
	else 
		return x*getPower(x,n-1);

	// return multiplication;
}






