//program 7.11.2.1.cpp  qsort用法示例
#include <iostream>
using namespace std;
int MyCompare( const void * elem1, const void * elem2 )
{
	unsigned int * p1, * p2;
	p1 = (unsigned int *)elem1; //*elem1无定义，要转换成 unsigned int *	
	p2 = (unsigned int *)elem2;		 
	return  (* p1 % 10)  - (* p2 % 10 ); 
}
const int  NUM = 5;
int main()
{
	unsigned int a[NUM] = { 8,123,11,10,4 };
	qsort( a, NUM, sizeof(unsigned int), MyCompare);  
	for( int i = 0;i < NUM; ++i )
		cout <<  a[i] << " ";
    return 0;
}

