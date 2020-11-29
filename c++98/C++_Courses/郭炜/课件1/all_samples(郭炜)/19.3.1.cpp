//program 19.3.1.cpp 函数对象示例
#include <iostream>
using namespace std;
class CAverage  
{
  public:
	double operator()( int a1, int a2, int a3 ) 
	{ //重载() 运算符， 
		return (double)(a1+a2+a3) / 3;
	}
};
int main()
{
	CAverage average;  //能够求三个整数平均数的函数对象
	cout << average(3,2,3); // 等价于cout <<average.operator(3,2,3);
	return 0;
}
