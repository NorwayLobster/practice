#include <cstdlib>
#include <cstdio>
#include <cstring>
int main(int argc,char ** argv){
	FILE * fp;
	if(argc<2){
		perror("args error\n");
		return -1;
	}
	printf("argv[1]:%s\n",argv[1]);
	fp=fopen(argv[1],"wb+");
//	fp=fopen(argv[1],"rb+");
//	fp=fopen(argv[1],"ab+");
	if(NULL==fp){
		perror("fopen error\n");
		return -1;
	}
	char buf[128]={0};
	printf("strlen(buf):%d\n",strlen(buf));
	printf("sizeof(buf):%d\n",sizeof(buf));
//	error:int ret=fread(buf,sizeof(char),strlen(buf)-1,fp);
	int ret=fread(buf,sizeof(char),sizeof(buf)-1,fp);
	printf("buf:%s\n",buf);
	printf("strlen(buf):%d\n",strlen(buf));
	printf("ret:%d\n",ret);
	char s1[128]="wangcheng";
//	ret=fwrite((const void*)s1,sizeof(char),(size_t)strlen(s1)-1,fp);
//	ret=fwrite(s1,sizeof(char),(size_t)strlen(s1)-1,fp);
	ret=fwrite(s1,sizeof(char),(size_t)strlen(s1),fp);
	printf("ret:%d\n",ret);
	fclose(fp);
	return -1;
}
