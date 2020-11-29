//program 19.8.1.cpp  变值算法示例
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;
void Modify( int & lst) { lst *= lst; }
int Square(int n) { return n * n; }
int Zero() { return 0; }
int One() { return 1; }
bool Even(int n) { return !(n % 2); } //判断n是否是偶数 
int main()  
{
	int a[6] = { 1,2,3,4,5,6}; 
	int b[6];
	copy(a,a+6,b);
	ostream_iterator<int> oit(cout,",");//定义用于输出的迭代器
	cout << "1) "; copy(b,b+6,oit); cout << endl;
		//输出 1) 1,2,3,4,5,6,
	copy_backward(b,b+4,b+5); //拷贝[b,b+4)到[b+1,b+5)
	cout << "2) "; copy(b,b+6,oit); cout << endl;
		//输出 2) 1,1,2,3,4,6,
	list<int> lst(5); //lst要有足够空间以支持后面的拷贝
	transform(a,a+5,lst.begin(),Square); 
		//将a中元素的平方拷贝到lst，a中的元素不会改变
	cout << "3) "; copy(lst.begin(),lst.end(),oit); cout << endl;
		//输出 3) 1,4,9,16,25,
	cout << "4) "; copy(a,a+6,oit); cout << endl;
		//输出4) 1,2,3,4,5,6, 说明a中元素没变
	swap_ranges(lst.begin(),lst.end(),b);//交换lst和b的内容
	cout << "5) ";copy(lst.begin(),lst.end(),oit); cout << endl;
		//输出 5) 1,1,2,3,4,
	fill(b,b+6,0); //b变成 0 0 0 0 0 0
	fill_n(b+2,3,1); //b变成 0 0 1 1 1 0
	cout << "6) ";copy(b,b+6,oit); cout << endl;
		//输出 6) 0,0,1,1,1,0,
	copy(a,a+6,b); //b 变成 1 2 3 4 5 6
	generate(b,b+6,Zero); //b变成 0 0 0 0 0 0
	generate_n(b+1,3,One); //b变成 0 1 1 1 0 0
	cout << "7) "; copy(b,b+6,oit); cout << endl;
		//输出 7) 0,1,1,1,0,0,
	replace(b,b+6,1,3); //将b中的1都替换成3
	cout << "8) "; copy(b,b+6,oit); cout << endl;
		//输出 8) 0,3,3,3,0,0,
	replace_if(b,b+6,Even,11); //将b中的偶数都替换成11
	cout << "9) "; copy(b,b+6,oit); cout << endl;
		//输出 9) 11,3,3,3,11,11,
	replace_copy(a,a+6,b,3,30);
		//拷贝a到b,但是拷贝过程中会将3替换成30,a不变
	cout << "10) "; copy(b,b+6,oit); cout << endl;
		//输出 10) 1,2,30,4,5,6,
	replace_copy_if(a,a+6,b,Even,7);
		//拷贝a到b,但是拷贝过程中偶数都被替换成7，a不变
	cout << "11) "; copy(b,b+6,oit); cout << endl;
		//输出 11) 1,7,3,7,5,7,
	return 0;
}

