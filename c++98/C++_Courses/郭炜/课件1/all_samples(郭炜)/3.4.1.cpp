//program 3.4.2.cpp   用牛顿迭代法求输入的数的平方根。
#include <iostream>
using namespace std;
const double EPS = 0.001; //用以控制计算精度
int main()
{
	double a;
	cin >> a ;  //输入a,要求a的平方根
	if( a >= 0) {
		double x = a/2,lastX = x + 1 + EPS;  //确保能够进行至少一次迭代
		while( x - lastX > EPS || lastX - x > EPS){ //只要精度未达要求，就继续迭代
			lastX = x;
			x = (x + a/x)/2;
		}
		cout << x;
	}
	else 
		cout << "It can't be nagitive.";
	return 0;
}

