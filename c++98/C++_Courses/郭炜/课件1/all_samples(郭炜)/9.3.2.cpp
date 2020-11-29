//program 9.3.2.cpp 二分法求方程根
#include <iostream>
#include <cmath>
#include <iomanip>
 using namespace std;
const double EPS = 1e-6;
inline double f(double x) {	return  x*x*x - 5*x*x + 10*x - 80; }
int main()
{
	double root, x1 = 0, x2 = 100,y;
	root = x1+(x2-x1)/2;
	y = f(root);
	int triedTimes = 1; //记录一共尝试多少次，对求根来说不是必须的
	while(abs(y) > EPS) {
		if( y > 0 )
			x2 = root;
		else
			x1 = root;
		root = x1+(x2 - x1)/2;
		triedTimes ++;
		y = f(root);
	}
	cout << setprecision(10) << root << endl;
	cout << triedTimes << endl;
	return 0;
}

