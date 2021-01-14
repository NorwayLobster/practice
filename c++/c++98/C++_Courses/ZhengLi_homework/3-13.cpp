#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
	int a;
	cin>>a;
	int Fibonacci(int a);
	cout<<Fibonacci(a)<<endl;
	return 0;
}



// 	int Fibonacci(int n){
// 	int sum=0;
// 	if(n==1 || n==2)
// 		sum=1;
// 	else 
// 		sum=Fibonacci(n-1)+Fibonacci(n-2);
// 	return sum;
// }



	int Fibonacci(int n){
	if(n<3)
		return 1;
	else 
		return Fibonacci(n-1)+Fibonacci(n-2);
}














