 ///
 /// @file    func.hpp
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-01-31 00:31:35
 ///
#ifndef __HEAD_HPP__ 
#define __HEAD_HPP__ 
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <cstring>
#include <string>
#include <memory>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>
#include <signal.h>
#include <pthread.h>
#include <assert.h>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <sys/epoll.h>

using std::max;
using std::vector;
using std::set;
using std::map;
using std::make_pair;
#define 	PERROR(val,ret,name)\
{	 char buf[1024]={0};sprintf(buf,"%s error",name); if((val)==(ret))\
	{ perror(buf); printf("errno:%d\n",errno);_exit(-1);}}

#define MAX_EVENT_NUMBER 1024
#define BUF_SIZE 10

//#ifndef __FILENAME__
//#define __FILENAME__
//char FILENAME[1024]="file";
//#endif
////char FILENAME[1024]="file";

typedef struct tag{
	pid_t pid;
	int busy;
	int fd;
}Data,*pData;

typedef struct train_tag{
	int len;
	char buf[4096];
}Train,*pTrain;

int sendn(int ,char *,int );
void recv_onceforall(int ,int ,set<int> &,char *);
void addFd(int ,int ,bool );
void delFd(int ,int );
void setNonbloking(int );
void sig_pipe_handler(int );
void createChildProcesses(pData ,int );
void child_handler(int );
int send_file(int ,char *,int );
void send_fd(int ,int ,int );
void recv_fd(int ,int *,int * );
#endif
