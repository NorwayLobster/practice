//program 16.6.3.cpp   sscanf和sprintf用法示例
#include <iostream>
using namespace std;
int main() 
{
	int a; char c; char s[20];
	char szSrc[] = "-28 K,test 1234567890123456";
	char szDest[200];
	long long n ;
	  sscanf(szSrc, "%d %c,%s%lld",&a,&c,s,&n); //从szSrc里读取数据
     sprintf(szDest, "%d %c %s %lld",a,c,s,n); //将数据输出到szDest
     printf("%s",szDest);
     return 0; 
}

