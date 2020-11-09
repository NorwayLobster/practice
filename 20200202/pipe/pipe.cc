 ///
 /// @file    open.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-02 22:00:27
 ///
 
#include "func.hpp"
int main(){

	int pipefds[2];
	int pipefds1[2];
	int ret;
	ret=pipe(pipefds);//pipefds[0] read end, pipefds[1] write end
	PERROR(-1,ret,"pipe()")
	ret=pipe(pipefds1);//pipefds[0] read end, pipefds[1] write end
	PERROR(-1,ret,"pipe()")

	pid_t pid;
	pid=fork();
	if(0==pid){
		printf("i am child\n");
		close(pipefds[0]);
		close(pipefds1[1]);

		ret=write(pipefds[1],"hello",5);
		PERROR(-1,ret,"write()")

		char buf[1024]={0};
		ret=read(pipefds1[0],buf,sizeof(buf));
		PERROR(-1,ret,"read()")
		puts(buf);

		close(pipefds[1]);
		close(pipefds1[0]);
	}
	else{
		printf("i am parent\n");
		close(pipefds[1]);
		close(pipefds1[0]);

		char buf[1024]={0};
		ret=read(pipefds[0],buf,sizeof(buf));
		PERROR(-1,ret,"read()")
		puts(buf);

		ret=write(pipefds1[1],"world",5);
		PERROR(-1,ret,"write()")

		wait(NULL);

		close(pipefds[0]);
		close(pipefds1[1]);
	}
	
	return 0;
}
