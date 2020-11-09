///
/// @file    fork_malloc.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-02 14:41:59
///

#include "func.hpp"
void print(){
	printf("print()");//note 无\n
	//在子函数中退出进程
//	exit(4);//刷新标准c库缓冲区
//	_exit(4);//不刷新标准c库缓冲区

}
int main(){
	print();
	printf("main()");
//	exit(4);//刷新标准c库缓冲区
//	_exit(4);//不刷新标准c库缓冲区
//
//
	abort();
	return 0;//主函数中退出进程
}
