///
/// @file    sem.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-03 17:55:42
///

#include "func.hpp"
int main(){
	key_t key=11111;
	int semflg=IPC_CREAT|0600;
	int msqid;
	msqid=msgget(key,semflg);
	PERROR(-1,msqid,"semget()");
	struct msqid_ds msq_ds;
	int cmd;

	cmd=IPC_STAT;
	msgctl(msqid,cmd,&msq_ds);

	printf("uid:%d,mode:%o,msq_num:%ld,msg_qbytes:%ld\n",msq_ds.msg_perm.uid,\
			msq_ds.msg_perm.mode,msq_ds.msg_qnum,msq_ds.msg_qbytes);


	msq_ds.msg_perm.mode=0666;
	cmd=IPC_SET;
	msgctl(msqid,cmd,&msq_ds);


	memset(&msq_ds,0,sizeof(msq_ds));

	cmd=IPC_STAT;
	msgctl(msqid,cmd,&msq_ds);
	printf("uid:%d,mode:%o,msq_num:%ld,msg_qbytes:%ld\n",msq_ds.msg_perm.uid,\
			msq_ds.msg_perm.mode,msq_ds.msg_qnum,msq_ds.msg_qbytes);
//			struct msqid_ds {
//			struct ipc_perm msg_perm;     /* Ownership and permissions */
//			time_t          msg_stime;    /* Time of last msgsnd(2) */
//			time_t          msg_rtime;    /* Time of last msgrcv(2) */
//			time_t          msg_ctime;    /* Time of last change */
//			unsigned long   __msg_cbytes; /* Current number of bytes in
//											 queue (nonstandard) */
//			msgqnum_t       msg_qnum;     /* Current number of messages
//											 in queue */
//			msglen_t        msg_qbytes;   /* Maximum number of bytes
//											 allowed in queue */
//			pid_t           msg_lspid;    /* PID of last msgsnd(2) */
//			pid_t           msg_lrpid;    /* PID of last msgrcv(2) */
//			};
//
//			The ipc_perm structure is defined as follows (the highlighted fields are
//				settable using IPC_SET):
//
//			struct ipc_perm {
//				key_t          __key;       /* Key supplied to msgget(2) */
//				uid_t          uid;         /* Effective UID of owner */
//				gid_t          gid;         /* Effective GID of owner */
//				uid_t          cuid;        /* Effective UID of creator */
//				gid_t          cgid;        /* Effective GID of creator */
//				unsigned short mode;        /* Permissions */
//				unsigned short __seq;       /* Sequence number */
//			};
//
//

			return 0;
}
