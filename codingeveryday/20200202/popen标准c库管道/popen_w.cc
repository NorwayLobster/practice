 ///
 /// @file    open.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-02 22:00:27
 ///
 
#include "func.hpp"
int main(){

	FILE * fp;
//popen()=fork()+pipe()
	fp=popen("./scanf","w");
	PERROR(NULL,fp,"popen()")
	int ret;
	char buf[1024]={0};
	ret=fwrite(buf,sizeof(char),sizeof(buf)/sizeof(char),fp);
	PERROR(0,ret,"fwrite()")

	ret=pclose(fp);
	PERROR(-1,ret,"pclose()")
	
	return 0;
}
