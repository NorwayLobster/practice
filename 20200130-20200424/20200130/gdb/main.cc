 ///
 /// @file    main.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-01-30 14:01:40
 ///
 
#include <cstdio>
#include <cstdlib>
int add(int a,int b){
	return a+b;
}
int main(int argc, char ** argv){
	printf("%d\n",argc);
	printf("%s\n",argv[0]);
	int a=atoi(argv[1]),b=atoi(argv[2]);
	for(int i=0;i<100;++i){
		int ret=add(a,b);
		printf("%d\n",ret);
	}
	return 0;
}
