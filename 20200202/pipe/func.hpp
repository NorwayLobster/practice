 ///
 /// @file    func.hpp
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-01-31 00:31:35
 ///
 
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <cstring>
#include <sys/wait.h>
#define 	PERROR(val,ret,name)\
{	 char buf[1024]={0};sprintf(buf,"%s error",name); if((val)==(ret)){ perror(buf); return -1; }}
