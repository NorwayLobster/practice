 ///
 /// @file    object_as_condition.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-29 21:06:34
 ///
 
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
	class Point {
public:
	Point(int x, int y)
	:a(x)
	,b(y)
	{
		cout<<"Point"<<endl;
	}
private:
		int a;
		int b;
	};
int main(void)
{
	Point p1(1,2);
	int a;
	// error: could not convert ‘p1’ from ‘Point’ to ‘bool’
//	if(p1)
//		cout<<"yes"<<endl;
//	else 
//		cout<<"no"<<endl;
	cin>>a;
	cout<<cin.eof()<<" "<<cin.fail()<<endl;
	if(cout)
	if(cin)
	//if(cin>>a)
		cout<<"yes,"<<"a="<<a<<endl;
	else 
		cout<<"no, a="<<a<<endl;
//	cout<<p1.a<<" " <<p1.b<<endl;
	return 0;
}
