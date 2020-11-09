 ///
 /// @file    print.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-01-31 02:18:30
 ///
 //
#include <head.hpp>
int main(){
	char str[100]=" ls  hello    4";
	char buf[100]={0};
	char str1[10]={0};
	char str2[10]={0};
	int num=0;
	int ret;
	ret=sscanf(str,"%s %s %d",str1,str2,&num);	
	PERROR(EOF,ret,"sscanf");	
	printf("%*s%s\n",5,"",str);
	printf("%5c%s\n",' ',str);
	printf("%s-%s-%d\n",str1,str2,num);
	sprintf(buf,"%s-%s-%d\n",str1,str2,num);
	puts(buf);
	printf("---");
	return 0;
}
