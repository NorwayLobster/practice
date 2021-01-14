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

	return 0;
}
