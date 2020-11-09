 ///
 /// @file    getpass.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-13 15:09:47
 ///
 
#include <head.hpp>
#include <crypt.h>

int get_salt(char * password,char *psalt){
		printf("in get_salt pw:%s\n",password);
		int i=0;
		for(int j=0;j<3;++i){
			if('$'==password[i]){
//				printf("pw[i]:%c\n",password[i]);
				++j;
			}
		}
		strncpy(psalt,password,i);
		return 0;
}
		
int get_ciphertext(char *pw,char *ciphertext){
}

int main(int argc,char **argv){
	if(2!=argc){
		perror("args error");
		_exit(1);
	}
	char *pw;
	pw=getpass("enter you password:");
	printf("pw:%s$\n",pw);

	struct spwd *password;
//	password=getspnam(argv[1]);
	PERROR(NULL,password,"getspnam");//非常重要

//	int getspnam_r(const char *name, struct spwd *spbuf, char *buf, size_t buflen, struct spwd **spbufp);
//
	printf("pw:%s\n",password->sp_pwdp);

	char salt[512]={0};

//	printf("pw:%s\n",ciphertext);
//	get_salt(ciphertext,salt);
//	get_salt(password->sp_pwdp,salt);
//	struct crypt_data ciphertext;
//	crypt_r(password->sp_pwdp,salt,&ciphertext);
	char * ciphertext=crypt(pw,salt);
	printf("salt:%s\n",salt);
	printf("ciphertext:%s\n",ciphertext);
	return 0;
}
