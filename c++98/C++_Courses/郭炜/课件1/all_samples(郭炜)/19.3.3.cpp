//program 19.3.3.cpp  函数对象在sort中的应用
#include <iostream>
#include <algorithm> //sort在此头文件中定义
using namespace std;
template <class T>
void PrintInterval( T first,T last)
{ //用以输出[first,last)中的元素
	for( ; first != last ; ++ first )
		cout << * first << " ";
	cout << endl;
}
class A
{
public:
	int v;	   
	A(int n):v(n) { }
};
bool operator <(const A & a1,const A & a2)
{//重载成A的const成员函数也可以，重载成非const成员函数在某些编译器上不行
 	 return a1.v < a2.v;
}
bool GreaterA( const A & a1, const A & a2)
{//v值大的元素算小的 
	return a1.v > a2.v;
}
struct LessA
{
	bool operator() ( const A & a1, const A & a2)
	{//按v的个位数小的元素，就算小的
		return (a1.v % 10) < (a2.v % 10);
	}
};
ostream & operator<<( ostream & o,const A & a)
{
	o << a.v;
	return o;
}
int main()
{
	int a1[4] = { 5,2,4,1};
	A a2[5] = {13,12,9,8,16};
	sort(a1,a1+4);
	cout << "1) "; PrintInterval(a1,a1+4); //输出 1) 1 2 4 5
	sort(a2,a2+5); // 按v的值从小到大排序
	cout << "2) "; PrintInterval(a2,a2+5); //输出 2) 8 9 12 13 16
	sort(a2,a2+5,GreaterA); //按v的值从大到小排序
	cout << "3) "; PrintInterval(a2,a2+5); //输出 3) 16 13 12 9 8
	sort(a2,a2+5,LessA()); //按v的个位数从小到大排序
	cout << "4) "; PrintInterval(a2,a2+5); //输出 4) 12 13 16 8 9
	return 0;
}

