///
/// @file    msgrvc_longge.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-06 17:41:23
///

#include "func.hpp"

typedef struct{
	long mtype;
	char buf[64];
}MSG;
int main()
{
	key_t key=11111;
	int msgid=msgget(key,IPC_CREAT|0600);
	if(-1==msgid)
	{
		perror("msgget");
		return -1;
	}
	printf("msqid:%d\n",msgid);

	MSG msg;
	bzero(&msg,sizeof(msg));
	msg.mtype=1;
	//	strcpy(msg.buf,"world");
	//	int ret=msgsnd(msgid,&msg,sizeof(msg.buf),0);
	//	if(-1==ret)
	//	{
	//		perror("msgsnd");
	//		return -1;
	//	}
	int ret=msgrcv(msgid,&msg,sizeof(msg.buf),1,0);
	if(-1==ret)
	{
		perror("msgrcv");
		return -1;
	}
	printf("ret=%d\n",ret);
	printf("buf=%s\n",msg.buf);
	return 0;
}

