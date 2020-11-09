 ///
 /// @file    read_onceforall.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-12 17:12:34
 ///
 
#include "head.hpp"

void recv_onceforall(int epfd,int sockfd,set<int> &fdset,char *buf){
//buf:”退化”成指向首元素的指针
		while(1){
			memset(buf,0,BUF_SIZE);
//			memset(buf,0,sizeof(buf));
			int ret=recv(sockfd,buf, BUF_SIZE-1,0);//这里少接收一个是为了print buf的时候有字符串结束符
//			ret=recv(sockfd,buf, sizeof(buf)-1,0);
			if(ret<0){
				if(EAGAIN==errno||EWOULDBLOCK==errno){
					printf("---finish recv-ing---\n");
					break;	
				}
				else{//什么情景???
					PERROR(-1,ret,"recv()");
					printf("recv() error\n");
					_exit(-1);//recv出错，服务器挂掉???
				}
			} //退出机制 对端ctrl+c退出，或ctrl+d退出
		   else if(ret==0){//水平触发，触发了表示有数据，ret应该大于0，但ret=0，表示sockfd关闭了
				fdset.erase(sockfd);
				delFd(epfd,sockfd);
				close(sockfd);//关闭后，不解除注册，是否一直使epollwait触发？？
				printf("bye %d\n",sockfd);
		//						continue;
				break;
			}else{
				printf("from client:%s\n",buf);
			}
		}
}


