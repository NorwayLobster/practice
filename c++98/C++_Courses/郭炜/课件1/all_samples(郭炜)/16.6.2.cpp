//program 16.6.2.cpp  输入输出long long类型和double类型变量
#include <iostream>
using namespace std;
int main() 
{
	int a;
	float f;
	double df;
	long long n = 9876543210001133LL; //64位整型常量要以 "LL"结尾
	scanf("%x:%e%le,%lld",&a,&f,&df,&n); //会跳过输入中的":"和"，" 
	printf("%d,%x,%f,%lf,%lld",a,a,f,df,n);
	return 0; 
}
