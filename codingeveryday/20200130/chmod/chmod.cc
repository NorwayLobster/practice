 ///
 /// @file    chmod.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-01-30 21:00:33
 ///
 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <sys/stat.h>
#include <unistd.h>
using std::cout;
using std::endl;
int main(int argc,char**argv){
	if(argc<2){
		perror("args error\n");
		return -1;
	}
	int ret=0;
//1.chmod()
	char pathName[128]=".";
	ret=chmod(pathName,0777);
	printf("%d\n",ret);
	ret =chmod(argv[1],0777);
	printf("%d\n",ret);

//2.getcwd()
	char buf[128]={0};
	char* result = getcwd(buf,sizeof(buf));
	//判断调用错误与否
	if(NULL==getcwd(buf,sizeof(buf))){
			perror("getcwd() error\n");
			return -1;
	}
	printf("buf:%s\n",buf);
	printf("result:%s\n",result);

	//
	char* p= getcwd(NULL,0);
	if(NULL==p){
			perror("getcwd() error\n");
			return -1;
	}
	printf("p:%s\n",p);

//3.chdir()
	bzero(pathName,strlen(pathName));
	strcpy(pathName,"/tmp/");
//	char pathName[128]="/tmp/";
	ret=chdir(pathName);
	char* result2 = getcwd(NULL,0);
	printf("%s\n",result2);
	printf("%d\n",ret);
	printf("%s\n",getcwd(NULL,0));



	return 0;
}
