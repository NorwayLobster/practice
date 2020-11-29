#include <iostream>
using namespace std;
class point
{
private:
	int _x;
	int _y;
public:
	point(int a=1,int b=2);
	point(const point &a)
	:_x(a._x)
	 ,_y(a._y)
	{
		cout<<"copy constructor"<<endl;
	}
	~point()
	{
		cout<<"deconstructor"<<endl;
	}
	//point();
	int print();
};

//point::point()
//{
//	_x = 0;
//	_y = 0;
//}
point::point(int a,int b)
{
	cout<<"constructor"<<endl;
//	cout<<"point()"<<endl;
	_x = a;
	_y = b;
}
int point::print()
{
	cout<<"_x=:"<<_x<<endl;
	cout<<"_y=:"<<_y<<endl;
	return 0;
}

int main(int argc, char*argv[])
{
//	point a(10,100);
//	point b;
	//point c(a);
//	point d=a;
	point d= point(10,100);
	//a.print(); 
	//b.print(); 
	//c.print(); 
	//d.print(); 
	return 0;
}
