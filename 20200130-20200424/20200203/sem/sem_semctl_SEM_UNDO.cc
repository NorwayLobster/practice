///
/// @file    sem.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-03 17:55:42
///

#include "func.hpp"
#define N 10000000
int main(){
	int ret;
	key_t key=1234;
	int nsems=1;//1个信号量
	int semflg=IPC_CREAT|0600;
	int semid;
	semid=semget(key,nsems,semflg);
	PERROR(-1,semid,"semget()");

	int cmd;
	cmd=SETVAL;
	int sem_no_th=0;
	int val=1;
	ret=semctl(semid,sem_no_th,cmd,val);	
	PERROR(-1,ret,"semctl()");

	cmd=GETVAL;
	ret=semctl(semid,sem_no_th,cmd);	
	PERROR(-1,ret,"semctl()");
	printf("getval:%d\n",ret);

	struct sembuf sops[2];
	int nsop=1;

//4.semop() sem_flg: SME_UNDO 防止死锁
	sops[0].sem_num=0;
	sops[0].sem_op=-1;//p lock
	sops[0].sem_flg=0;
//	sops[0].sem_flg=SEM_UNDO;//当主进程挂掉，其信号量自动解锁

	sops[1].sem_num=0;
	sops[1].sem_op=1;//v unlock
	sops[1].sem_flg=0;
//	sops[1].sem_flg=SEM_UNDO;






	int shmid=shmget(1234,4096,IPC_CREAT|0600);
	PERROR(-1,shmid,"shmget()");
	int *p=(int*)shmat(shmid,NULL,0);
	//attention 初始化
	p[0]=0;
	
	pid_t pid;
	pid=fork();
	PERROR(-1,pid,"fork()");

	if(0==pid){
		printf("child\n");
		ret=semop(semid,sops,nsop);
		PERROR(-1,ret,"semop() p op");
		printf("you can see me or not\n");
		ret=semop(semid,sops+1,nsop);
		PERROR(-1,ret,"semop() v  op");
		return 0;
	}
	else{
		printf("parent\n");
		ret=semop(semid,sops,nsop);
		PERROR(-1,ret,"semop() p op");
		while(1);
		ret=semop(semid,sops+1,nsop);
		PERROR(-1,ret,"semop() v  op");
		wait(NULL);
		printf("p[0]:%d\n",p[0]);
		return 0;
	}

	return 0;
}
