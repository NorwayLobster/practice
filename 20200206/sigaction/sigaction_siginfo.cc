///
/// @file    sig.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-06 22:07:07
///

#include "func.hpp"

void sig(int signum,siginfo_t* p,void *p1){
//	siginfo_t {
//		int      si_signo;     /* Signal number */
//		int      si_errno;     /* An errno value */
//		int      si_code;      /* Signal code */
//		int      si_trapno;    /* Trap number that caused
//								  hardware-generated signal
//								  (unused on most architectures) */
//		pid_t    si_pid;       /* Sending process ID */
//		uid_t    si_uid;       /* Real user ID of sending process */
//		int      si_status;    /* Exit value or signal */
//		clock_t  si_utime;     /* User time consumed */
//		clock_t  si_stime;     /* System time consumed */
//		sigval_t si_value;     /* Signal value */
//		int      si_int;       /* POSIX.1b signal */
//		void    *si_ptr;       /* POSIX.1b signal */
//		int      si_overrun;   /* Timer overrun count;
//								  POSIX.1b timers */
//		int      si_timerid;   /* Timer ID; POSIX.1b timers */
//		void    *si_addr;      /* Memory location which caused fault */
//		long     si_band;      /* Band event (was int in
//								  glibc 2.3.2 and earlier) */
//		int      si_fd;        /* File descriptor */
//		short    si_addr_lsb;  /* Least significant bit of address
//								  (since Linux 2.6.32) */
//		void    *si_call_addr; /* Address of system call instruction
//								  (since Linux 3.5) */
//		int      si_syscall;   /* Number of attempted system call
//								  (since Linux 3.5) */
//		unsigned int si_arch;  /* Architecture of attempted system call
//								  (since Linux 3.5) */
//	}

	printf("before sleep,signum %d is comming\n",signum);

	sleep(2);	
	sigset_t pend;
	memset(&pend,0,sizeof(pend));
	int ret;

	ret=sigpending(&pend);
	PERROR(-1,ret,"sigpending()");

	ret=sigismember(&pend,SIGQUIT);
	PERROR(-1,ret,"sigismember()");
	if(1==ret){
		printf("%d is pending\n",SIGQUIT);
	}else{
		printf("%d is not pending\n",SIGQUIT);
	}

	printf("after sleep,signum %d is comming\n",signum);
	printf("si_pid:%d,si_uid:%d\n",p->si_pid,p->si_uid);



}

int main(){
	//	sighandler_t ret;
	int ret;
	struct sigaction sigac;
	memset(&sigac,0,sizeof(sigac));
	//	struct sigaction {
	//		void     (*sa_handler)(int);
	//		void     (*sa_sigaction)(int, siginfo_t *, void *);
	//		sigset_t   sa_mask;
	//		int        sa_flags;
	//		void     (*sa_restorer)(void);
	//	};
	//
	sigac.sa_sigaction=sig;
	sigac.sa_flags=SA_SIGINFO;
	//	sigac.sa_mask=;

	sigemptyset(&sigac.sa_mask);
	sigaddset(&sigac.sa_mask,SIGQUIT);

	ret=sigaction(SIGINT,&sigac,NULL);
	ret=sigaction(SIGQUIT,&sigac,NULL);
	PERROR(-1,ret,"sigaction()");

	while(1);
	//sleep(10);//信号过来 唤醒,后，剩余的时间 没用了，直接退出了

	return 0;
}
