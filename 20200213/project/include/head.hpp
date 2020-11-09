 ///
 /// @file    func.hpp
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-01-31 00:31:35
 ///
#ifndef __HEAD_HPP__ 
#define __HEAD_HPP__ 
#include<md5sum.hpp>

#include <sys/sendfile.h>
#include <sys/mman.h>
#include<pwd.h>
#include <time.h>
#include<grp.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <cstdio>
#include <iostream>
#include <memory>
#include <cstring>// strcpy()等
#include <string>//  string类
#include <algorithm>//  string类

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
#include <shadow.h>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sys/epoll.h>

#include <mysql/mysql.h>

using std::max;
using std::vector;
using std::set;
using std::map;
using std::queue;
using std::make_pair;

using std::string;
using std::reverse;
using std::shared_ptr;

void rwx(unsigned int a,string & s);
int ls(char *,char *);
#define handle_error(msg) \
	   do { perror(msg); exit(EXIT_FAILURE); } while (0)
//EXIT_SUCCESS 
#define 	PERROR(val,ret,name)\
do{	 char buf[1024]={0};sprintf(buf,"%s error",name); if((val)==(ret))\
	{ perror(buf); printf("errno:%d\n",errno);_exit(-1);}}while(0)


#define MAX_EVENT_NUMBER 1024
#define BUF_SIZE 10

//#ifndef __FILENAME__
//#define __FILENAME__
//char FILENAME[1024]="file";
//#endif
////char FILENAME[1024]="file";

typedef void*(*threadFunc)(int,void*);
typedef struct tag{
	pid_t pid;
	int busy;
	int fd;
}Data,*pData;

typedef struct task_tag{
	queue<int> sockfdqueue;
	int capacity;
//	int size;
}TaskQueue,*pTaskQueue;

typedef struct threadnode_tag{
	pthread_t pid;
}ThreadNode,*pThreadNode;

typedef struct threadPool_tag{
	pThreadNode pNodeArr;
	TaskQueue taskqueue;

	pthread_mutex_t mutex;
	pthread_cond_t cond;
	threadFunc taskfunc;
	int exit_flag;
	int thead_num;
}ThreadPool,*pThreadPool;




typedef struct train_tag{
	int len;
	char buf[4092];
}Train,*pTrain;

void recv_onceforall(int ,int ,set<int> &,char *);
void addFd(int ,int ,bool );
void delFd(int ,int );
void setNonbloking(int );
void sig_pipe_handler(int );
void createChildProcesses(pData ,int );
void child_handler(int );

//int send_file(int ,char *,int );
int send_file(int newfd,int fd,int offset);
int sendn(int ,char *,int );
void send_fd(int ,int ,int );

int recv_file(int newfd);
int recv_file(int newfd,char *filename,int len);
int recv_file(int newfd,int ,int len);
int recvn(int fd,char *buf,int len);
void recv_fd(int ,int *,int * );

void createChildThreads(ThreadPool *,int );
void * thread_func(void *);

void threadPool_destroy(ThreadPool *pTp);
void threadPool_init(ThreadPool *pTp,threadFunc f,int threadNum,int );
void *task_handler(int newfd,void*p);

int send_train(int newfd,Train *p_t,char * buf);
int recv_train(int newfd,Train *p_t,char * buf);
int login_or_signup_authentication_client(int newfd);

int generate_rand_string(char *str,int num);
int	generate_salt(char *salt);

int mysql_insert(char *query);
int mysql_query_my(char *,char **);

struct UserCurrentInfo{
	char username[64];
	char user_root_dir[64];	// /home/cheng/baiduwangpan/test1
	char cur_full_dir[64];	// / 登陆的时候
	char baiduwangpan_root_dir[64];	// /home/cheng/baiduwangpan
	int pre_dir_code;// 0  0 表示无pre_dir, 自己就是根
	int cur_dir_code;// 1
	int login_success_flag;	
};

int login_authentication_server(int ,UserCurrentInfo*);
int signup_authentication_server(int ,UserCurrentInfo*);
int pwd(int ,UserCurrentInfo*);
int mk_dir(int newfd,struct UserCurrentInfo * p_user_cur_info,char * arg1);
int cd(int newfd,struct UserCurrentInfo * p_user_cur_info,char * arg1);
int ls_new(int ,UserCurrentInfo*);

int send_file_server(int newfd,struct UserCurrentInfo * p_user_cur_info,char *arg1,int arg2);
int send_file_client(int newfd,char *arg1);
int recv_file_client(int newfd,char *arg1);
int recv_file_server(int newfd,struct UserCurrentInfo * p_user_cur_info,char *arg1,int arg2);

int send_file_by_mmap(int newfd,char * file_real_full_path,int file_size_byte);
int recv_file_by_mmap(int newfd,char * file_real_full_path,int file_size_byte);

int send_file_by_sendfile(int newfd,char * file_real_full_path,int file_size_byte);
#endif
