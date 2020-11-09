///
/// @file    fork_malloc.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-02 14:41:59
///

#include "func.hpp"
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unistd.h>
int add(int,int);
int main(int argc,char** argv){
	if(2!=argc){
		perror("args error");
		return -1;
	}
	int ret;
	//1.ftok()
	int proj_id=2;
	key_t key;
	key=ftok(argv[1],proj_id);
	PERROR(-1,key,"ftok()");
	printf("key:%d\n",key);

	size_t size=4096;
	int shmid;
	//2.shmget()
	int shmflag;
#if 1
	shmflag=IPC_CREAT|0666;
	shmid=shmget(key,size,shmflag);
	PERROR(-1,shmid,"shmget()");
	printf("shmid:%d\n",shmid);

#endif

#if 0
	//2.1.shmget()
	shmflag=IPC_CREAT|0666|IPC_EXCL;//IPC_EXCL如果发现该key,已经存在，就报错
	shmid=shmget(key,size,shmflag);
	PERROR(-1,shmid,"shmget()");
	printf("shmid:%d\n",shmid);
#endif

#if 0
	//2.2.shmget()
	key=IPC_PRIVATE;//用于亲缘进程
	shmflag=IPC_CREAT|0666;
	shmid=shmget(key,size,shmflag);
	PERROR(-1,shmid,"shmget()");
	printf("shmid:%d\n",shmid);

#endif
	//3.shmat()
//	int *p;
//	p=(int*)shmat(shmid,NULL,0);
//	PERROR((int*)-1,p,"shmat");
//	printf("p[0]:%d\n",p[0]);

	char *p;
	p=(char*)shmat(shmid,NULL,0);
	PERROR((char*)-1,p,"shmat");
	printf("p:%p\n",p);
	char str_buf[1024]={0};
	strcpy(str_buf,"helloword");
	strcpy(p,str_buf);
	puts(p);
//	while(1);
#if 0
	//4.shmdt()
	ret=shmdt(p);
	PERROR(-1,ret,"shmdt()");

#endif 

	struct shmid_ds buf;
	memset(&buf,0,sizeof(struct shmid_ds));


//	struct shmid_ds {
//		struct ipc_perm shm_perm;    /* Ownership and permissions */
//		size_t          shm_segsz;   /* Size of segment (bytes) */
//		time_t          shm_atime;   /* Last attach time */
//		time_t          shm_dtime;   /* Last detach time */
//		time_t          shm_ctime;   /* Last change time */
//		pid_t           shm_cpid;    /* PID of creator */
//		pid_t           shm_lpid;    /* PID of last shmat(2)/shmdt(2) */
//		shmatt_t        shm_nattch;  /* No. of current attaches */
//		...
//	};

//	struct ipc_perm {
//		key_t          __key;    /* Key supplied to shmget(2) */
//		uid_t          uid;      /* Effective UID of owner */
//		gid_t          gid;      /* Effective GID of owner */
//		uid_t          cuid;     /* Effective UID of creator */
//		gid_t          cgid;     /* Effective GID of creator */
//		unsigned short mode;     /* Permissions + SHM_DEST and
//									SHM_LOCKED flags */
//		unsigned short __seq;    /* Sequence number */
//	};
//

	//7.shmctl():IPC_STAT
	int cmd;
	cmd=IPC_STAT;
	ret=shmctl(shmid,cmd,&buf);
	PERROR(-1,ret,"shmctl() IPC_STAT");
	printf("cuid=%d,mode=%o,size=%ld,nattach=%ld\n",buf.shm_perm.cuid,buf.shm_perm.mode,buf.shm_segsz,buf.shm_nattch);

	//6.shmctl():IPC_SET
	cmd=IPC_SET;
	buf.shm_perm.mode=0765;
	ret=shmctl(shmid,cmd,&buf);
	PERROR(-1,ret,"shmctl() IPC_SET");
	printf("cuid=%d,mode=%o,size=%ld,nattach=%ld\n",buf.shm_perm.cuid,buf.shm_perm.mode,buf.shm_segsz,buf.shm_nattch);

#if 1
	//5.shmctl():IPC_RMID//标记删除 dest当nattach数为1时，才删除
	cmd=IPC_RMID;
	ret=shmctl(shmid,cmd,NULL);
	PERROR(-1,ret,"shmctl() IPC_RMID");
	while(1);
#endif
	return -1;
}
