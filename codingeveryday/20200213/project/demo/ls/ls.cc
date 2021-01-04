 ///
 /// @file    mkdir.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-01-31 00:29:46
 ///
 
#include <head.hpp>

//note: struct stat 中 mode_t 为
//unsigned int


int ls(char * p_path,char *response){
	int  ret;
	DIR * p_dir;
	p_dir=opendir(p_path);
//	printf("p_dir:%p\n",p_dir);
	if(NULL==p_dir){
		perror("opendir error\n");
		return -1;
	}

	struct passwd * p_passwd;
	struct group * p_group;
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
	string s_rwx;
	struct stat * p=(struct stat *)calloc(1,sizeof(struct stat));
	char buf[64]={0};

	shared_ptr<struct stat> shared_ptr(p);
	while(NULL!=(p_dirent=readdir(p_dir))){
	//	printf("d_ino:%ld,d_off:%ld,d_reclen:%d,d_type:%d,d_name:%s\n",p_dirent->d_ino,p_dirent->d_off,p_dirent->d_reclen,p_dirent->d_type,p_dirent->d_name);
//		printf("----------------------------\n");
		ret=stat(p_dirent->d_name,p);
		if(-1==ret){
			perror("stat() error\n");
			return -1;
		}
		memset(buf,0,sizeof(buf));
		p_passwd=getpwuid(p->st_uid);//多线程不安全 MT-unsafe
		//printf("pw_name:%s\n",p_passwd->pw_name);
		p_group=getgrgid(p->st_gid);//MT-unsafe
		//printf("gr_name:%s\n",p_group->gr_name);
//		printf("shared_ptr->st_dev:%ld,shared_ptr->st_ino:%ld,shared_ptr->st_mode:%u,shared_ptr->st_nlink:%ld,shared_ptr->st_uid:%d,shared_ptr->st_gid:%d,\
shared_ptr->st_rdev:%ld,shared_ptr->st_size:%ld,shared_ptr->st_blksize:%ld,shared_ptr->st_blocks:%ld,shared_ptr->st_atime:%ld,\
shared_ptr->st_mtime:%ld,shared_ptr->st_ctime:%ld\n",\
shared_ptr->st_dev,shared_ptr->st_ino,shared_ptr->st_mode,shared_ptr->st_nlink,shared_ptr->st_uid,shared_ptr->st_gid,\
shared_ptr->st_rdev,shared_ptr->st_size,shared_ptr->st_blksize,shared_ptr->st_blocks,shared_ptr->st_atime,\
shared_ptr->st_mtime,shared_ptr->st_ctime);
		rwx(shared_ptr->st_mode,s_rwx);
		reverse(s_rwx.begin(),s_rwx.end());
		ctime_r(&shared_ptr->st_ctime,buf);
		buf[strlen(buf)-1]='0';
//		printf("%s %4ld %8s %8s %10ld %10ld %10ld %10ld %s %-s\n" ,s_rwx.c_str(),shared_ptr->st_nlink,p_passwd->pw_name,p_group->gr_name,shared_ptr->st_rdev,shared_ptr->st_size,shared_ptr->st_blksize,shared_ptr->st_blocks,buf+4,p_dirent->d_name);
		sprintf(response,"%s %4ld %8s %8s %10ld %10ld %10ld %10ld %s %-s\n" ,s_rwx.c_str(),shared_ptr->st_nlink,p_passwd->pw_name,p_group->gr_name,shared_ptr->st_rdev,shared_ptr->st_size,shared_ptr->st_blksize,shared_ptr->st_blocks,buf+4,p_dirent->d_name);
		//printf("%ld,%ld,%s,%ld,%d,%d,%ld,%ld,%ld,%ld,%s,%s,%s\n", shared_ptr->st_dev,shared_ptr->st_ino,s_rwx.c_str(),shared_ptr->st_nlink,shared_ptr->st_uid,shared_ptr->st_gid, shared_ptr->st_rdev,shared_ptr->st_size,shared_ptr->st_blksize,shared_ptr->st_blocks,ctime(&shared_ptr->st_atime), ctime(&shared_ptr->st_mtime),ctime(&shared_ptr->st_ctime)+4);
//		printf("\n");
		s_rwx.clear();
//	       char *ctime_r(const time_t *timep, char *buf);


	}



#if 0

//2.ctime()
	p=(struct stat *)calloc(1,sizeof(struct stat));
		ret=stat(p_path,p);
		if(-1==ret){
			perror("stat() error\n");
			return -1;
		}
		printf("st_mtime:%ld-----\n",shared_ptr->st_mtime);
		printf("st_mtime:%s-----\n",ctime(&shared_ptr->st_mtime));
	

//0.static_cast<>()
	int *p_int =static_cast<int*>(calloc(10,sizeof(int)));

//3.getpwuid()
		printf("st_uid:%d\n",p->st_uid);

//		struct passwd * p_passwd =static_cast<struct passwd *>(calloc(1, sizeof(struct passwd)));
		p_passwd=getpwuid(p->st_uid);
		printf("pw_name:%s\n",p_passwd->pw_name);
		p_group=getgrgid(p->st_gid);
		printf("gr_name:%s\n",p_group->gr_name);

//attention: free(p_passwd);//系统自动负责在该进程中对p_passwd的指向内存的释放

//4.getgrgid()
		printf("st_uid:%d\n",p->st_uid);
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

int main(int argc, char**argv){
	if(argc!=3){
		perror("args error\n");
		return -1;
	}
	ls(argv[1]);
	return 0;
}
