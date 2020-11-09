 ///
 /// @file    add.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-02 17:21:25
 ///
 
#include <cstdio>
#include <cstdlib>
int main(int argc,char ** argv){
	if(3!=argc){
		perror("args error");
		return -1;
	}
	int a=atoi(argv[1]);
	int b=atoi(argv[2]);
	printf("%d,%d,a+b:%d\n",a,b,a+b);
	return 0;
}

