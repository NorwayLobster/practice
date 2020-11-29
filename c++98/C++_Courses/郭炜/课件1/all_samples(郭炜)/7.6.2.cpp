//program 7.6.2.cpp  指针作为函数参数也是传值
#include <iostream>
using namespace std;
void Swap(int *p1, int *p2)
{
	int *tmp = p1; //保存p1指向的位置
	p1 = p2;  //p1指向p2指向的位置
	p2 = tmp; //p2指向p1原来指向的位置
}
int main()
{
	int m = 4, n = 3;
	int *pm = & m; //p1指向m
	int *pn = & n; //p2指向n
	Swap(pm,pn); 
	cout << *pm << "," << *pn;  //输出 4,3
}

