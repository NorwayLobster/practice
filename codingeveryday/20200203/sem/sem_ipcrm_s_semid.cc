///
/// @file    sem.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-03 17:55:42
///

#include "func.hpp"
#define N 10000000
int main(){
	int ret;
//1.semget()
	key_t key=1234;
	int nsems=1;//1个信号量
	int semflg=IPC_CREAT|0600;
	int semid;
	semid=semget(key,nsems,semflg);
	PERROR(-1,semid,"semget()");

//2.semctl()
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

//3.semop()
//The elements of this structure are of type struct sembuf,  containing
//	the following members:
//
//  unsigned short sem_num;  /* semaphore number */
//	short          sem_op;   /* semaphore operation */
//	short          sem_flg;  /* operation flags */

	struct sembuf sops[2];
	int nsop=1;//the no of sem you want to op on this time;

//4.semop() sem_flg: SME_UNDO
	sops[0].sem_num=0;
	sops[0].sem_op=-1;//p lock
//	sops[0].sem_flg=0;
	sops[0].sem_flg=SEM_UNDO;

	sops[1].sem_num=0;
	sops[1].sem_op=1;//v unlock
//	sops[1].sem_flg=0;
	sops[1].sem_flg=SEM_UNDO;






	int shmid=shmget(1234,4096,IPC_CREAT|0600);
	PERROR(-1,shmid,"shmget()");
	int *p=(int*)shmat(shmid,NULL,0);
	//attention 初始化
	p[0]=0;
	
	pid_t pid;
	pid=fork();
	PERROR(-1,pid,"fork()");
	time_t start,end;
//note:正在执行循坏时， 可以电话用
	if(0==pid){
		printf("child\n");
		for(int i=0;i<N;++i){
			ret=semop(semid,sops,nsop);
			PERROR(-1,ret,"semop() v  op");
			p[0]+=1;
			ret=semop(semid,sops+1,nsop);
			PERROR(-1,ret,"semop() v  op");
		}
		return 0;
	}
	else{
		printf("parent\n");

		start=time(NULL);
		for(int i=0;i<N;++i){
			ret=semop(semid,sops,nsop);
			PERROR(-1,ret,"semop() v  op");
			p[0]+=1;
			ret=semop(semid,sops+1,nsop);
			PERROR(-1,ret,"semop() v  op");
		}
		wait(NULL);
		end=time(NULL);

		printf("p[0]:%d\n",p[0]);
		printf("time:%ld\n",end-start);
	//	return 0; //note: 主进程结束，下面的代码无法执行
	}

	
//5.semctl() IPC_RMID
	cmd=IPC_RMID;
	ret=semctl(semid,0,cmd);
	PERROR(-1,ret,"semctl() ipc_rmid");
	return 0;
}
