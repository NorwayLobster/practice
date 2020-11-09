 ///
 /// @file    fork.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-07 14:04:57
 ///
 
#include  "func.hpp"
int main(){
	if(!fork()){
		while(1);//child
	}
	else{
		while(1);//
	}
	return 0;
}

