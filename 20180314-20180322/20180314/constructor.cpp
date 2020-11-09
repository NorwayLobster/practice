#include <iostream>
using namespace std;
class point
{
private:
	int xPos;
	int yPos;
public:
	point(int a=1,int b=2);
	//point();
	int print();
};

//point::point()
//{
//	xPos = 0;
//	yPos = 0;
//}
point::point(int a,int b)
{
	xPos = a;
	yPos = b;
}
int point::print()
{
	cout<<"xPos=:"<<xPos<<endl;
	cout<<"yPos=:"<<yPos<<endl;
	return 0;
}

int main(int argc, char*argv[])
{
	point a(10,100);
	point b;
	point c(b);
	point d=a;
	a.print(); 
	b.print(); 
	c.print(); 
	d.print(); 
	return 0;
}
