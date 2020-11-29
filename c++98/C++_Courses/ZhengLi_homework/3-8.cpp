#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{	
	double a,b;
	cout<<"please input Fahrenheit temperature degree:";
	cin>>a;
	double convertTemperature(double a);
	cout<<"the temperature degree in Celsius is:"<<convertTemperature(a)<<endl;
	return 0;
}



double convertTemperature(double a){
	return 5.0/9*(a-32);
}

