//program 16.6.1.cpp scanf和printf用法示例
#include <iostream>
using namespace std;
int main() 
{
	int a;
	char b;
	char c[20];
	double d = 0;
	float e = 0;
	int n = scanf("%d%c%s%lf%f",&a,&b,c,&d,&e);
	printf("result:  %d %c %s %lf %e %f %d\n",a,b,c,d,e,e,n);
	return 0; 
}

