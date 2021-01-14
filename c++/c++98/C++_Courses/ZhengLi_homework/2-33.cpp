#include<iostream>
#include <stdlib.h>
using namespace std;

enum Weekday {Sunday, Monday, Tuseday, Wenesday, Thursday, Friday, Staturday};

int main(){
	
	int a;
	Weekday day1=Friday,day2=Sunday;
	cout<<"day1=:"<<day1<<endl;
	cout<<"day1=:"<<(Weekday)day1<<endl;

	day1=Monday;
	a=(Weekday) 6;
	int b= day1;

	cout<<"a=:"<<a<<'\n'<<"b=:"<<(enum Weekday)b<<endl;

	// cin>>day2;
	cout<<"day2:"<<day2<<endl;

}/////?????????????