//program 14.4.1.cpp 派生类的构造函数和析构函数调用顺序
#include <iostream>
#include <string>
using namespace std;
class CBug  {
		int legNum,color;
	public:
		CBug (int ln, int cl):legNum(ln),color(cl) 
		{ 
			cout << "CBug Constructor" <<endl;
		};
		~CBug() 
		{
			cout << "CBug Destructor" << endl;
		}
		void PrintInfo() 
		{
			cout << legNum << "," << color <<endl;
		}

};
class CFlyingBug: public CBug 
{
		int wingNum;
	public:
		// CFlyingBug( ) { } 若不注释掉则会编译出错
		CFlyingBug::CFlyingBug ( int ln, int cl, int wn):CBug(ln,cl),wingNum(wn) 
		{
			cout << "CFlyingBug Constructor" <<endl;
		}
		~CFlyingBug() 
		{
			cout << "CFlyingBug Destructor" << endl;
		}

};
int main() {
	CFlyingBug fb(2,3,4);
	fb.PrintInfo ();
	return 0;
}

