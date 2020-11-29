//program 3.1.1.cpp  判断整数奇偶性
#include <iostream>
using namespace std;
int main()
{
 	int n;
 	cin >> n;
 	if( n % 2 == 1) 
  		 cout << "It's odd." ;   //当 n % 2 == 1 成立时会执行此语句
 	else
 		 cout << "It's even." ;  //当 n % 2 == 1 不成立时会执行此语句
 	return 0;
}

