 ///
 /// @file    homework.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-01-31 01:36:49
 ///
 
#include <func.hpp>
#include <cstring>
int main(int argc, char**argv){
	if(3!=argc){
		perror("args error\n");
		return -1;
	}
	DIR * p_dir; 
	p_dir=opendir(argv[1]);
	struct dirent * p_dirent;
	printf("argv[1]:%s\n",argv[1]);
	printf("argv[2]:%s\n",argv[2]);

	while(NULL!=(p_dirent=readdir(p_dir))){
		printf("p_dirent->d_name:%s\n",p_dirent->d_name);
		if(0==strcmp(argv[2],p_dirent->d_name)){
			printf("file %s exists\n",argv[3]);
			break;
		}
	}
	if(NULL==p_dirent)
		printf("file %s does not exist\n",argv[2]);
			
	return 0;
}
	
