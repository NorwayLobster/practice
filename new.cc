 ///
 /// @file    new.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-27 17:10:33
 ///
#include <cstring> 
#include <cstdio>
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;
int main(int argc, char**argv)
{
//	int a=10;
	int * p1=(int *)malloc(sizeof(int)*10);
//	bzero(p1,10);
	memset(p1,'a',10*4);
//	*p1 = 1000;
//*p1 = a;
	for(int i=0;i<10;++i)
	{
		//p2[i] = i;
		cout<<*((char*)p1+i)<<endl;
	}
	cout<<"*p1="<<*p1<<endl;
	free(p1);
	
	int *p2 = new int [10];
	int *p3 = new int(289);
	cout<<"*p3="<<*p3<<endl;
	delete p3;
	for(int i=0;i<10;++i)
	{
		//p2[i] = i;
		cout<<*(p2+i)<<endl;
	}
	::printf("hello\n");
	//error: delete [10] p2;	
	delete [] p2;
	return 0;
}
