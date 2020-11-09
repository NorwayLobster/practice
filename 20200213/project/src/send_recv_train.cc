 ///
 /// @file    send_recv_train.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-15 01:18:54
 ///
 
#include <head.hpp>

int send_train(int newfd,Train *p_t,char * buf){
	int ret;
	memset(p_t,0,sizeof(Train));
	p_t->len=strlen(buf);
	memcpy(p_t->buf,buf,p_t->len);
	ret=sendn(newfd,(char*)p_t,4+p_t->len);
	if(-1==ret) return -1;
	return 0;
}
	//ret=send(sfd,buf, strlen(buf)-1,0);
int recv_train(int newfd,Train *p_t,char * buf){
	int ret;
	memset(p_t,0,sizeof(Train));
	ret=recvn(newfd,(char*)p_t,4);
	if(-1==ret) return -1;
	ret=recvn(newfd,p_t->buf,p_t->len);
	if(-1==ret) return -1;
	memcpy(buf,p_t->buf,p_t->len);
	return 0;
}


