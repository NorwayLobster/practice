///
/// @file    gmtime.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-01 22:56:53
///

#include "func.hpp"
int main(){
	for(int i=0;i<10;++i){
		if(!fork()){
			printf("i am child %d\n",i);
			while(1);
		}
	}
	printf("i am parent\n");
	wait(NULL);
	return 0;
}
