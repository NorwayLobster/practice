//scanf string 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	char*a=(char*)malloc(sizeof(char)*10);
	memset(a,0,sizeof(char)*10);
	char b[1024]={0};
	scanf("%s",a);
	a[9]=0;
	scanf("%s",b);
	puts(a);
	puts(b);
	return 0;
}
