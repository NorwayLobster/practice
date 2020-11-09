 ///
 /// @file    homework.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-01-31 01:36:49
 ///
 
#include <func.hpp>
#include <cstring>
void checkFileorDir(const char* pathName,const char *name);
int main(int argc, char**argv){
	if(3!=argc){
		perror("args error\n");
		return -1;
	}
	printf("argv[1]:%s\n",argv[1]);
	printf("argv[2]:%s\n",argv[2]);
	checkFileorDir(argv[1],argv[2]);
	return 0;
}

void checkFileorDir(const char* pathName,const char *name){
	DIR * p_dir; 
	struct dirent * p_dirent;
	p_dir=opendir(pathName);
	char buf[1024]={0};
	while(NULL!=(p_dirent=readdir(p_dir))){
		if(0==strcmp(p_dirent->d_name,".")||0==strcmp(p_dirent->d_name,"..")){
			continue;
		}
		memset(buf,0,sizeof(buf));
		sprintf(buf,"%s%s%s",pathName,"/",p_dirent->d_name);
		printf("%s\n",buf);
		if(0==strcmp(name,p_dirent->d_name)){
			printf("------------------\nfile %s exists\n------------------\n",name);
		}
		if(p_dirent->d_type==4){
			checkFileorDir(buf,name);
		}
		
	}
			
}
	
