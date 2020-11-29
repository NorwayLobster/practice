//program 5.4.1.cpp 
#include <iostream>
#include <string> //使用string须包含此头文件 
using namespace std;
string weekdays[] = { "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };
int main()
{
 	int n;
 	cin >> n;
	if( n > 7 || n < 1 )
		cout << "Illegal";
	else
		cout << weekdays[n-1];
	return 0;
}

