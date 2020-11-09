 ///
 /// @file    login_or_signup_authentication_client.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-15 17:11:59
 ///
 
#include <head.hpp>
int login_or_signup_authentication_client(int newfd){
	char login_text[8]="login";
	char signup_text[8]="signup";
	char login_answer[8]={0};
	char signup_answer[8]={0};

	Train t;
	int signup_flag=0;
	char username[32]={0};	
	char salt[32]={0};	
	int success;
	char *pw;
	char * ciphertext;

	printf("login(yes/no)?:");
	scanf("%s",login_answer);
	if(0==strcmp("",login_answer)||0==strcmp("yes",login_answer)||0==strcmp("y",login_answer)){
			
	}else{
		printf("signup(yes/no)?:");
		scanf("%s",signup_answer);
		puts(signup_answer);
		if(0==strcmp("",signup_answer)||0==strcmp("yes",signup_answer)||0==strcmp("y",signup_answer)){
			signup_flag=1;
			puts(signup_answer);
		}else{
			return -1;
		}
	}

	printf("enter your username?:");
	scanf("%s",username);
	pw=getpass("enter you password:");
	printf("pw:%s$\n",pw);
	printf("username:%s\n",username);

	if(signup_flag){
		printf("signup_flag:%d\n",signup_flag);
		send_train(newfd,&t,signup_text);
		send_train(newfd,&t,username);
		recv_train(newfd,&t,salt);
		printf("salt:%s\n",salt);
		if(0==strcmp("",salt)){
			return -1;
		}

		ciphertext=crypt(pw,salt);
		printf("ciphertext:%s\n",ciphertext);
		send_train(newfd,&t,ciphertext);
		recv_train(newfd,&t,(char*)&success);
		printf("success:%d\n",success);
		-1==success?printf("sorry, failed to signup\n"):printf("congratulations,signup success\n");
		return	-1==success?-1:0;	
	}else{
		printf("signup_flag:%d\n",signup_flag);
		send_train(newfd,&t,login_text);
		send_train(newfd,&t,username);
		recv_train(newfd,&t,salt);
		printf("salt:%s\n",salt);
		if(0==strcmp("",salt)){
			printf("sorry, no this username, go and signup\n");
			return -1;
		}

		ciphertext=crypt(pw,salt);
		printf("ciphertext:%s\n",ciphertext);
		send_train(newfd,&t,ciphertext);
		recv_train(newfd,&t,(char*)&success);
		printf("success:%d\n",success);
		-1==success?printf("sorry, failed to login\n"):printf("congratulations, login success\n");
		return	-1==success?-1:0;	
	}

	return 0;
}

#ifdef DEBUG
int main(){
	int newfd=0;
	login_or_signup_authentication_client(newfd);
	return 0;
}
#endif
