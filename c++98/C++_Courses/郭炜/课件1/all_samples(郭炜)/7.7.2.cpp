//program 7.7.2.cpp 起泡排序
#include <iostream>
using namespace std;
void BubbleSort( int * pa, int size)
{//起泡排序
	for( int i = size -1 ; i > 0; i -- ) 
		for( int j = 0; j < i; j ++) 
			if( pa[j] > pa[j+1] ) {
				int tmp = pa[j];
				pa[j] = pa[j+1];
				pa[j+1] = tmp;
			}			
}
const int NUM = 5;
int main()  
{
	int a[NUM] = {5,4,8,2,1 };
	BubbleSort(a, NUM);	//将数组a从小到大排序
	for( int i = 0;i <NUM; ++i)
		cout << a[i] << " ";
    return 0;
}

