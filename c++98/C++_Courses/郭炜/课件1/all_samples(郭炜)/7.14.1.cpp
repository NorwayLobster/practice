//program 7.14.1.cpp  指针数组示例
#include <iostream>
using namespace std;
int main()
{
	char ** p;
	char * countries [] = { "China","USA","Japan","France"};
	p = countries; // p指向countries[0]
	for( int i = 0;i < 4;++i ) 
		cout << * ( p + i ) << endl;
	cout << * ((* p) + 3) << endl;
	return 0;
}

