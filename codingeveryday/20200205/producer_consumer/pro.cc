///
/// @file    sem.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-03 17:55:42
///

#include "func.hpp"
#define N 1000
int main(){
	int ret;
	key_t key=11111;
	int nsems=2;//1个信号量
	int semflg=IPC_CREAT|0600;
	int semid;
	semid=semget(key,nsems,semflg);
	PERROR(-1,semid,"semget()");

//第一个信号量表示仓位位置， 第二个表示生产产品数量
//




	struct sembuf sops[2];
	sops[0].sem_num=0;
	sops[0].sem_op=-1;//p lock
	sops[0].sem_flg=SEM_UNDO;

	sops[1].sem_num=1;
	sops[1].sem_op=1;//v unlock
	sops[1].sem_flg=SEM_UNDO;


	int nsop=1;//the no of sem you want to op on this time;//信号量集合中第一个信号量表为0号，作用在几个信号量上
	while(1){

		printf("product no:%d\n",semctl(semid,1,GETVAL));
		printf("free space no:%d\n",semctl(semid,0,GETVAL));

		printf("produce one product\n");
		sleep(3);// 生产行为结束


		//计数信号量状态更新
		ret=semop(semid,sops,nsop);//生产一个,即放进仓库一个，即仓库位置少一个，-1
		PERROR(-1,ret,"semop() -1");
		ret=semop(semid,sops+1,nsop);//生产一个,产品加一个,+1
		PERROR(-1,ret,"semop() +1");
		printf("product no:%d\n",semctl(semid,1,GETVAL));
		printf("free space no:%d\n",semctl(semid,0,GETVAL));
		printf("\n");

	}
	return 0;
}
