 ///
 /// @file    sscanf.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-01-30 20:30:36
 ///
 
#include <iostream>
#include <cstdio>
#include <cstring>
using std::cout;
using std::endl;
int main(int argc,char** argv){
	if(argc<3){
		perror("arg error\n");
		return -1;
	}
	char s1[128]="10 cheng 200";
	int a,b;
	char name[10]={0};
	printf("name:%s\n",name);
//1.sscanf()
	sscanf(s1,"%d %s%d",&a,name,&b);
	printf("a:%d\n",a);
	printf("name:%s\n",name);
	printf("b:%d\n",b);

	char buf[128]={0};

//2.sprintf()
	sprintf(buf,"%d %s %d",a,name,b);
	printf("buf:%s\n",buf);
//3.fprintf()
	FILE *fp;
	fp=fopen(argv[1],"ab+");
	fprintf(fp,"%d %s %d",a,name,b);

//4.fscanf()
	char str[128]={0};
	FILE *fp1;
	fp1=fopen(argv[2],"ab+");
	char addr[12];
	int age,height;
	memset(addr,0,sizeof(addr));
	fscanf(fp1,"%d %s %d %s",&age,name,&height,addr);
	printf("age:%d\n",age);
	printf("name:%s\n",name);
	printf("height:%d\n",height);
	printf("addr:%s\n",addr);
	return 0;
}
