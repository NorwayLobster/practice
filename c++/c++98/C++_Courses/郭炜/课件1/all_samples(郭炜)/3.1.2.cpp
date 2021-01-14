//program 3.1.2.cpp  判断年份是否是建国、建党十周年或闰年
#include <iostream>
using namespace std;
int main()
{
	int year;
	cin >> year;
	if( year <= 0) 
		cout << "Illegal year." ;
	else {
		cout << "Legal year." << endl;
		if( year > 1949 && (year - 1949) % 10 == 0 )     //建国整十周年
			cout << "Luky year.";
		else if( year > 1921 && !((year - 1921) % 10))   //建党整十周年
			cout << "Good year.";		 
		else if( year % 4 == 0 && year % 100 || year % 400 == 0 )  //闰年
			cout << "Leap year";
		else
			cout << "Common year.";
	}
	return 0;
}

