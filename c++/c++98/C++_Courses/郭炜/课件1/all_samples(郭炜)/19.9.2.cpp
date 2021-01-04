//program 19.9.2.cpp  删除算法示例
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset函数在此声明
#include <iterator>
using namespace std;
bool LessThan4( int n) { return n < 4; }
int main()
{
	int a[5] = { 1,2,3,2,5};
	int b[6] = { 1,2,5,2,5,6};
	int c[6] = { 0,0,0,0,0,0};
	ostream_iterator<int> oit(cout,",");
	remove_if(b,b+6,LessThan4);//删除小于4的元素
	cout << "1) "; copy(b,b+6,oit); cout << endl; 	//输出 1) 5,5,6,2,5,6,
	int * p = remove_copy(a,a+5,c,2); //等于2的元素不拷贝
	cout << "2) " << p - c << endl; 		         //输出 2) 3
	cout << "3) "; copy(c,c+6,oit); cout << endl; //输出 3) 1,3,5,0,0,0,
	cout << "4) "; copy(a,a+5,oit); cout << endl; //输出 4) 1,2,3,2,5,
	                                              //说明remove_copy不改变源区间
	memset(c,0,sizeof(c)); //把 c 置为全0
	remove_copy_if(a,a+5,c,LessThan4); //小于4的元素不拷贝
	cout << "5) "; copy(c,c+6,oit); cout << endl; //输出 5) 5,0,0,0,0,0
	int d[7] = { 1,2,2,2,3,3,4 };
	vector<int> v;
	v.insert(v.begin(),d,d+7);
	unique(d,d+7); 
	cout << "6) "; copy(d,d+7,oit); cout << endl;	//输出 6) 1,2,3,4,3,3,4,
	memset(d,0,sizeof(d));
	unique_copy(v.begin(),v.end(),d);
	cout << "7) ";copy( d,d+7,oit);		         //输出 7) 1,2,3,4,0,0,0,
	return 0;
}

