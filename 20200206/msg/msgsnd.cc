///
/// @file    sem.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-03 17:55:42
///

#include "func.hpp"
typedef struct msgbuf_tag{
		long mtype;
//fatal error: int mtype;
		char mtext[64];
}Msg;
int main(){
	key_t key=11111;
	int semflg=IPC_CREAT|0600;
	int msqid;
	msqid=msgget(key,semflg);
	PERROR(-1,msqid,"msgget()");



	Msg message;
	message.mtype=1;
	memset(message.mtext,0,sizeof(message.mtext));

//	strcpy(message.mtext,"chengwang hello, programmer");
//传送int
	int a=12;
	memcpy(message.mtext,&a,sizeof(int));
	//strcpy(message.mtext,"helloworld");
	puts(message.mtext);

	int ret;

	int msgflg=0;
	ret=msgsnd(msqid,&message,sizeof(message.mtext),msgflg);
	PERROR(-1,ret,"msgsnd()");

	return 0;
}
