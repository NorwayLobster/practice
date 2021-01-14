// Sample4-2
#include <iostream>
using namespace std;

class Point
{
public:

	Point(int xx=0, int yy=0){
		x=xx;
		y=yy;

	}

	Point(Point &p);

	int getX(){
		return x;

	}

	int getY(){
		return y;
	}

private:
	int x, y;


};


Point::Point(Point &p){
	x=p.x;
	y=p.y;
	cout<<"Calling the copy constructor"<<endl;

}


void fun1(Point p){
	cout<<p.getX()<<endl;

}

Point fun2(){
	Point a(1,2);
	return a;
}



int main(int argc, char const *argv[])
{
	Point a(4,5);

	cout<<"case1: 1st calling for initialization"<<endl;
	Point b=a;
	cout<<"case1: 2nd calling for initialization"<<endl;
	Point c(a);
	cout<<b.getX()<<endl;

	cout<<"case2: 3rd calling for diliver actual parameter to form parameter."<<endl;
	fun1(b);

	cout<<"case3: 4rd calling for returning a objedt for a funtion"<<endl;


	b=fun2();

	cout<<b.getY()<<endl;

	cout<<c.getX()<<c.getY()<<endl;

	return 0;
}