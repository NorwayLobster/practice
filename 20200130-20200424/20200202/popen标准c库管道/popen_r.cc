 ///
 /// @file    open.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-02 22:00:27
 ///
 
#include "func.hpp"
int main(){

	FILE * fp;
	fp=popen("./print","r");
	PERROR(NULL,fp,"popen()")
	int ret;
	char buf[1024]={0};
	char *p=fgets(buf,sizeof(buf),fp);
	PERROR(NULL,p,"fgets()")

	puts(buf);

	ret=pclose(fp);
	PERROR(-1,ret,"pclose()")
	
	return 0;
}
