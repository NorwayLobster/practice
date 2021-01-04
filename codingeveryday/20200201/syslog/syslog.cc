 ///
 /// @file    syslog.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-01 22:43:21
 ///
 
#include <syslog.h>
int main(){
	syslog(LOG_INFO,"cheng log %d\n",234);
	setlogmask();
	openlog(LOG_INFO,"cheng log %d\n",234);
	closelog();

	return 0;
}
