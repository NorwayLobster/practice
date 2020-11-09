 ///
 /// @file    main.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-30 14:01:40
 ///
 
#include <cstdio>
#include <cstdlib>
#include <add.hpp>
#include <minus.hpp>
#include <print.hpp>
int main(int argc, char ** argv){
	printf("%d\n",argc);
	printf("%s\n",argv[0]);
	int a=atoi(argv[1]),b=atoi(argv[2]);
	print(a,b);
	for(int i=0;i<10;++i){
		int ret=add(a,b);
		int ret1=minus(a,b);
		print(ret,ret1);
	}
	return 0;
}
