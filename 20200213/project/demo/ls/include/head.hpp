 ///
 /// @file    func.hpp
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-01-31 00:31:35
 ///
 
#include<pwd.h>
#include <time.h>
#include<grp.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <cstdio>
#include <memory>
#include <cstring>// strcpy()等
#include <string>//  string类
#include <algorithm>//  string类
using std::string;
using std::reverse;
using std::shared_ptr;
void rwx(unsigned int a,string & s);
