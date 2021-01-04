 ///
 /// @file    mkdir.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-01-31 00:29:46
 ///
 
#include <func.hpp>
int main(int argc, char**argv){
	if(argc!=4){
		perror("args error\n");
		return -1;
	}
	int  ret;
//1.mkdir()	
	ret=mkdir(argv[1],0777);
	printf("ret:%d\n",ret);
	if(-1==ret){
		perror("mkdir error\n");
		return -1;
	}
	

//2.rmdir()	
	ret=rmdir(argv[2]);
	printf("ret:%d\n",ret);
	if(-1==ret){
		perror("rmdir error\n");
		return -1;
	}

//3.opendir()	
	DIR * p_dir;
	p_dir=opendir(argv[3]);
	printf("p_dir:%p\n",p_dir);
	if(NULL==p_dir){
		perror("opendir error\n");
		return -1;
	}

//4.readdir()	
	struct dirent *p_dirent;
	p_dirent=readdir(p_dir);
	printf("p_dirent:%p\n",p_dirent);
	if(NULL==p_dirent){
		perror("readdir error\n");
		return -1;
	}
	printf("d_ino:%ld,d_off:%ld,d_reclen:%d,d_type:%d,d_name:%s\n",p_dirent->d_ino,p_dirent->d_off,p_dirent->d_reclen,p_dirent->d_type,p_dirent->d_name);
	while(NULL!=(p_dirent=readdir(p_dir))){
		printf("d_ino:%ld,d_off:%ld,d_reclen:%d,d_type:%d,d_name:%s\n",p_dirent->d_ino,p_dirent->d_off,p_dirent->d_reclen,p_dirent->d_type,p_dirent->d_name);
	}

//5.rewinddir()	
	rewinddir(p_dir);
	printf("\n");
	printf("after rewinddir()\n");
	while(NULL!=(p_dirent=readdir(p_dir))){
		printf("d_ino:%ld,d_off:%ld,d_reclen:%d,d_type:%d,d_name:%s\n",p_dirent->d_ino,p_dirent->d_off,p_dirent->d_reclen,p_dirent->d_type,p_dirent->d_name);
	}
//6.telldir()	
	printf("\n");
	rewinddir(p_dir);
	p_dirent=readdir(p_dir);
	long int d_off=telldir(p_dir);
	printf("d_off:%ld\n",d_off);
//7.seekdir()	
	printf("after seekdir()\n");
	d_off=8014623958783977718;
	printf("d_off:%ld\n",d_off);
	seekdir(p_dir,d_off);
	p_dirent=readdir(p_dir);
	printf("d_ino:%ld,d_off:%ld,d_reclen:%d,d_type:%d,d_name:%s\n",p_dirent->d_ino,p_dirent->d_off,p_dirent->d_reclen,p_dirent->d_type,p_dirent->d_name);
//8.closedir()	
	closedir(p_dir);
	printf("ret:%d\n",ret);
	if(-1==ret){
		perror("closedir error\n");
		return -1;
	}



	return 0;
}
