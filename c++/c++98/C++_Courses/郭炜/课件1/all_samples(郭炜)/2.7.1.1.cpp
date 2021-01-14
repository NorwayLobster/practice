//program 2.7.1.1.cpp
#include <iostream>
using namespace std;
int main()  
{  		
		unsigned int n1 = 0xffffffff;
		cout << n1 << endl;   //输出4294967295
		unsigned int n2 = n1 + 3; //导致溢出
		cout << n2 << endl;   //输出2
		return 0;
}

