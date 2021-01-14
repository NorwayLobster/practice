//program 5.1.1.cpp  选择排序
#include <iostream>
using namespace std;
const  int MAX_NUM =100;
int main()
{
	int a[MAX_NUM];
	int n;
	cin >> n; //共有n个整数待排序 
	for( int i = 0;i < n ;++i )  //输入n个整数	
		cin >> a[i];
	//下面对整个数组进行从小到大排序
	for( int i = 0; i < n - 1; ++i ){  //第i次循环后就将第i小的元素放好
		int tmpMin = i;    //用来记录从第i个到第n-1个元素中，最小的那个元素的下标
		for( int j = i; j < n; ++j) {
			if( a[j] < a[tmpMin] ) 
				tmpMin = j;
		}
	 //下面将第i小的元素放在第i个位子上，并将原来占着第i个位子的那个元素挪到后面
		int tmp = a[i];
		a[i] = a[tmpMin];  
		a[tmpMin] = tmp;   
	}
	//下面两行将排序好的n个元素输出
	for( int i = 0;i < n ;++i)
		cout << a[i] << endl;
	return 0;
}

