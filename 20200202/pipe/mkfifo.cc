 ///
 /// @file    open.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-02 22:00:27
 ///
 
#include "func.hpp"
int main(){

	int ret;
	ret=mkfifo("./1.fifo",0666);
	PERROR(-1,ret,"mkfifo()")

	return 0;
}

