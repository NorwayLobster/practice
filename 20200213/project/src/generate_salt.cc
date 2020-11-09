 ///
 /// @file    generate_salt.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-15 02:31:19
 ///
 
#include <head.hpp>

int generate_rand_string(char *str,int num){
	srand(time(NULL));
	int flag;
	for(int i=0;i<num;++i){
		flag=rand()%3;
		switch(flag){
			case 0: str[i]=rand()%26+'a';break;
			case 1: str[i]=rand()%26+'A';break;
			case 2: str[i]=rand()%10+'0';break;
		}
	}
	return 0;
}
int	generate_salt(char *salt){
	int ret;
	int num=8;
	char str[9]={0};
	ret=generate_rand_string(str,num);

	strcpy(salt,"$6$");
	memcpy(salt+3,str,8);
	salt[3+8]='$';
	printf("salt:%s\n",salt);
	return ret;
}
		
#ifdef __MAIN__ 
int main(){
	char salt[16]={0};
	generate_salt(salt);
}
#endif
