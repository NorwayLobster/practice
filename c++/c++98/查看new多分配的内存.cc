 ///
 /// @file    查看new多分配的内存.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-29 13:03:58
 ///
 
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;
int main(void)
{
	int *p=(int*)malloc(sizeof(int)*2);
	::memset(p,'a',4);
	//int *p=new int(20);
	printf("%d\n",*(p-1));
	printf("%d\n",*(p-2));
	printf("%c\n",*((char*)p));
//	char* p1 = (char*)p;
//	cout<<(p-1)<<endl;
//	cout<<*(p-1)<<endl;
//	cout<<p<<endl;
//	cout<<*((char*)p)<<endl;
}
