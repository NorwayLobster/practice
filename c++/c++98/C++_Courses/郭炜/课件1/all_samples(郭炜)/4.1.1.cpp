//program 4.1.1.cpp  求三角形三条边长
#include <iostream>
using namespace std;
const double EPS = 0.001; //用以控制计算精度
double Sqrt(double a)
{ //求a的平方根
	 double x = a/2,lastX = x + 1 + EPS;  //确保能够进行至少一次迭代
	 while( x - lastX > EPS || lastX - x > EPS) {  
     //只要精度没有达到要求，就继续迭代
		lastX = x;
		x = (x + a/x)/2;
	 }
	 return x;
}
double Distance(double x1,double y1,double x2,double y2)
{//求两点(x1,y1),(x2,y2) 的距离 
     return Sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
 	int x1,y1,x2,y2,x3,y3;
 	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
 	cout << Distance(x1,y1,x2,y2) << endl;//输出(x1,y1)到（x2,y2）距离
 	cout << Distance(x1,y1,x3,y3) << endl;
 	cout << Distance(x3,y3,x2,y2) << endl;
	return 0;
}		

