///
/// @file    sem.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-03 17:55:42
///

#include "func.hpp"
typedef struct msgbuf_tag {
	long mtype;       /* message type, must be > 0 */
	char mtext[1024];    /* message data */
}MSG;


int main(){
	int ret;
	key_t key=11111;
	int semflg=IPC_CREAT|0600;
	int msqid;
	msqid=msgget(key,semflg);
	PERROR(-1,msqid,"semget()");

	MSG msg;
	memset(&msg,0,sizeof(msg));

	int pid;	
	pid=fork();
	PERROR(-1,pid,"fork()");
	if(0==pid){
		printf("child\n");
		int msgflg=0;	
		msg.mtype=1;
		sleep(10);
		ret=msgrcv(msqid,&msg,sizeof(msg.mtext),msg.mtype,msgflg);
		PERROR(-1,ret,"msgrcv()");
		printf("mtext:%s\n",msg.mtext);
	}
	else{
		//msgsnd(msqid,);
		printf("parent\n");
		int msgflg=0;	
		memcpy(msg.mtext,"hell-",5);
		printf("mtext:%s\n",msg.mtext);

		msg.mtype=1;//send之前，必须设置
		ret=msgsnd(msqid,&msg,sizeof(msg.mtext),msgflg);
		PERROR(-1,ret,"msgsnd()");
		wait(NULL);

		int cmd=IPC_RMID;
//		struct msqid_ds msq_ds;
//		msgctl(msqid,cmd,&msq_ds);
		msgctl(msqid,cmd,NULL);

	}
	return 0;

}







