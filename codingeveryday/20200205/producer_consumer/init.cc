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
	int cmd;
	cmd=SETALL;
	int sem_no_th=0;
	unsigned short array[2]={10,0};

	ret=semctl(semid,sem_no_th,cmd,array);	//selall 参数使函数忽略sem_no_th参数
	PERROR(-1,semid,"semctl() SETALL");
	return 0;
}
