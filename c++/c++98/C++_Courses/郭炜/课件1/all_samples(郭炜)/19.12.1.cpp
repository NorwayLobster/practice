//program 19.12.1.cpp 有序区间算法示例
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstring>
using namespace std;
class A
{
	public:
		int v;
		A(int n):v(n) { }
		A(){ v = 0;};
};
bool operator< ( const A & a1, const A & a2)
{
	return a1.v < a2.v;
}
ostream & operator <<( ostream & o, const A & a)
{
	cout << a.v;
	return o;
}
int main()  
{
	ostream_iterator<A> oit(cout,",");
	A a[7] = { 1,2,2,3,3,5,6 };
	A b[3] = { 3,4,6};
	A c[20]; 
	A d[4] = { 2,2,2,3 };
	A e[6] = { 2,2,2,3,7,7 };
	cout << "1) " << binary_search(a,a+7,A(3)) << endl;//输出 1) 1
	cout << "2) " << binary_search(a,a+7,A(100)) << endl; //输出 2) 0
	cout << "3) " << includes(a,a+6,b,b+3) << endl; //输出 3) 0
	A * p = lower_bound(a,a+7,3); 
	cout << "4) " << p - a << endl; //输出 4) 3
	p = upper_bound(a,a+7,3); 
	cout << "5) " << p - a << endl; //输出 5) 5
	pair<A * ,A *> pi = equal_range(a,a+7,3);
	cout << "6) " << pi.first - a << "," << pi.second - a << endl; //输出 6) 3,5
	p = merge(a,a+7,b,b+3,c);
	cout << "7) "; copy(c,p,oit); cout << endl; //输出 7) 1,2,2,3,3,3,4,5,6,6,
	memset(c,0,sizeof(c)); //把c变成全0
	p = set_union(a,a+7,b,b+3,c);
	cout << "8) "; copy(c,p,oit); cout << endl; //输出 8) 1,2,2,3,3,4,5,6,
	memset(c,0,sizeof(c));
	p = set_intersection(a,a+7,d,d+4,c);
	cout << "9) "; copy(c,p,oit); cout << endl; //输出 9) 2,2,3,
	memset(c,0,sizeof(c));
	p = set_difference(a,a+7,d,d+4,c); 
	cout << "10) "; copy(c,p,oit); cout << endl; //输出 10) 1,3,5,6,
	p = set_symmetric_difference(a,a+7,e,e+6,c);
	cout << "11) "; copy(c,p,oit); cout << endl; //输出 11) 1,2,3,5,6,7,7,
	A f[8] = { 2,4,6,8,1,3,5,7};
	inplace_merge(f,f+4,f+8);
	cout << "12) "; copy(f,f+8,oit); cout << endl; //输出 12) 1,2,3,4,5,6,7,8,
	return 0;
}

