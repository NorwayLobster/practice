 ///
 /// @file    homework.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-01-31 01:36:49
 ///
 
#include <func.hpp>
#include <cstring>
void printfdir(const char *pathName);
int main(int argc, char**argv){
	if(2!=argc){
		perror("args error\n");
		return -1;
	}
	printfdir(argv[1]);
	return 0;
}

void printfdir(const char *pathName){
	DIR * p_dir;
	struct dirent * p_dirent;
	p_dir=opendir(pathName);

	char buf[1024]={0};
	while(NULL!=(p_dirent=readdir(p_dir))){
		memset(buf,0,sizeof(buf));
//printf("%*s%s\n",p_dirent->d_name);
		if(0==strcmp(p_dirent->d_name,".")||0==strcmp(p_dirent->d_name,"..")){
			continue;
		}
		sprintf(buf,"%s%s%s",pathName,"/",p_dirent->d_name);
		printf("%s\n",buf);
		if(p_dirent->d_type==4){
			printfdir(buf);
		}
	}
			
}
	
