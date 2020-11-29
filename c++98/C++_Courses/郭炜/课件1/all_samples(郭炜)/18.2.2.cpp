//program 18.2.2.cpp  成员函数模版
#include <iostream>
using namespace std;
template <class T>
class A
{
public:
	template<class T2>  
	void Func( T2 t) { cout << t; } //成员函数模板
};
int main()  
{
	A<int> a;
	a.Func('K'); //成员函数模板 Func被实例化
	return 0;
}
