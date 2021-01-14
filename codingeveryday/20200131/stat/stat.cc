 ///
 /// @file    mkdir.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-01-31 00:29:46
 ///
 
#include <func.hpp>
#include<pwd.h>
#include <time.h>
#include<grp.h>
int main(int argc, char**argv){
	if(argc!=3){
		perror("args error\n");
		return -1;
	}
	int  ret;
	DIR * p_dir;
	p_dir=opendir(argv[1]);
	printf("p_dir:%p\n",p_dir);
	if(NULL==p_dir){
		perror("opendir error\n");
		return -1;
	}

	struct dirent *p_dirent;
//	p_dirent=readdir(p_dir);
//	printf("p_dirent:%p\n",p_dirent);
//	if(NULL==p_dirent){
//		perror("readdir error\n");
//		return -1;
//	}
//
//	printf("d_ino:%ld,d_off:%ld,d_reclen:%d,d_type:%d,d_name:%s\n",p_dirent->d_ino,p_dirent->d_off,p_dirent->d_reclen,p_dirent->d_type,p_dirent->d_name);
//

//1.stat()	
	struct stat * p=(struct stat *)calloc(1,sizeof(struct stat));
	shared_ptr<struct stat> shared_ptr(p);
	while(NULL!=(p_dirent=readdir(p_dir))){
		printf("d_ino:%ld,d_off:%ld,d_reclen:%d,d_type:%d,d_name:%s\n",p_dirent->d_ino,p_dirent->d_off,p_dirent->d_reclen,p_dirent->d_type,p_dirent->d_name);
		printf("----------------------------\n");
		ret=stat(p_dirent->d_name,p);
		if(-1==ret){
			perror("stat() error\n");
			return -1;
		}
		printf("shared_ptr->st_dev:%ld,shared_ptr->st_ino:%ld,shared_ptr->st_mode:%x,shared_ptr->st_nlink:%ld,shared_ptr->st_uid:%d,shared_ptr->st_gid:%d,\
shared_ptr->st_rdev:%ld,shared_ptr->st_size:%ld,shared_ptr->st_blksize:%ld,shared_ptr->st_blocks:%ld,shared_ptr->st_atime:%ld,\
shared_ptr->st_mtime:%ld,shared_ptr->st_ctime:%ld\n",\
shared_ptr->st_dev,shared_ptr->st_ino,shared_ptr->st_mode,shared_ptr->st_nlink,shared_ptr->st_uid,shared_ptr->st_gid,\
shared_ptr->st_rdev,shared_ptr->st_size,shared_ptr->st_blksize,shared_ptr->st_blocks,shared_ptr->st_atime,\
shared_ptr->st_mtime,shared_ptr->st_ctime);
		printf("%ld,%ld,%x,%ld,%d,%d,  %ld,%ld,%ld,%ld,%s,  %s,%s\n",\
shared_ptr->st_dev,shared_ptr->st_ino,shared_ptr->st_mode,shared_ptr->st_nlink,shared_ptr->st_uid,shared_ptr->st_gid,\
shared_ptr->st_rdev,shared_ptr->st_size,shared_ptr->st_blksize,shared_ptr->st_blocks,ctime(&shared_ptr->st_atime),\
ctime(&shared_ptr->st_mtime),ctime(&shared_ptr->st_ctime)+4);
		printf("\n");
		

	}




//2.ctime()
	p=(struct stat *)calloc(1,sizeof(struct stat));
		ret=stat(argv[2],p);
		if(-1==ret){
			perror("stat() error\n");
			return -1;
		}
		printf("st_mtime:%s\n",ctime(&shared_ptr->st_mtime));
		printf("\n");
	

//0.static_cast<>()
	int *p_int =static_cast<int*>(calloc(10,sizeof(int)));

//3.getpwuid()
		printf("st_uid:%d\n",p->st_uid);

#if 1
//		struct passwd * p_passwd =static_cast<struct passwd *>(calloc(1, sizeof(struct passwd)));
		struct passwd * p_passwd;
		p_passwd=getpwuid(p->st_uid);
		printf("pw_name:%s\n",p_passwd->pw_name);

//attention: free(p_passwd);//系统自动负责在该进程中对p_passwd的指向内存的释放

//4.getgrgid()
		printf("st_uid:%d\n",p->st_uid);
		struct group * p_group;
//		struct group * p_group =static_cast<struct group*>(calloc(1, sizeof(struct group)));
		p_group=getgrgid(p->st_gid);
		printf("gr_name:%s\n",p_group->gr_name);

//		free(p_group);



	ret = closedir(p_dir);
	printf("ret:%d\n",ret);
	if(-1==ret){
		perror("closedir error\n");
		return -1;
	}


#endif 

	return 0;
}
