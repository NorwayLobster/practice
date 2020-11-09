 ///
 /// @file    pwd.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-17 00:49:11
 ///
 
#include <head.hpp>

int pwd(int newfd,struct UserCurrentInfo * p_user_cur_info){
	Train t;
	int ret;
	ret=send_train(newfd,&t,p_user_cur_info->cur_full_dir);
	return ret;

}
