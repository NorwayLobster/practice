///
/// @file    sem.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-03 17:55:42
///

#include "func.hpp"
typedef struct msgbuf_tag{
		long mtype;
		//fatal error:int mtype;
		char mtext[64];
}Msg;
int main(){
	key_t key=11111;
	int flg=IPC_CREAT|0600;
	int msqid;
	msqid=msgget(key,flg);
	PERROR(-1,msqid,"msgget()");
	printf("msqid:%d\n",msqid);


	int ret;

	Msg message;
	message.mtype=1;
	memset(message.mtext,0,sizeof(message.mtext));


	printf("msqid:%d\n",msqid);
	int msgflg=0;
//	ret=msgrcv(msqid,&message,sizeof(message.mtext),message.mtype,msgflg);
	ret=msgrcv(msqid,&message,sizeof(message.mtext),1,0);
	PERROR(-1,ret,"msgrcv()");

	printf("msqid:%d\n",msqid);
//传送 int
	printf("message.mtext:%d\n",*(int*)message.mtext);

	puts(message.mtext);

	return 0;
}
