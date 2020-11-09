 ///
 /// @file    main.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-29 06:35:34
 ///
 
#include <bits/stdc++.h>
using namespace std;
int err_no=0;
void replaceSpaceInString(char *str){
//corner case 1:
	if(NULL==str){
		err_no=-1;
		return ;
	}
//corner case 2:
	if(0==strlen(str)){
		return ;
	}

	char *pLeft=str;	
	char *pRight;	
	char *pNewRight;	
	int numOfSpace=0;
	while('\0'!=*pLeft){
		if(' '==*pLeft){
			++numOfSpace;
		}
		++pLeft;
	}
//corner case 3:
	if(0==numOfSpace){
		return ;
	}
	pLeft=str;
	cout<<"numOfSpace:"<<numOfSpace<<endl;
	int len=strlen(str);
	pRight=str+len-1;
	pNewRight=str+len+2*numOfSpace-1;
//	*pNewRight='\0';
//	--pNewRight;
	while(pLeft<=pRight){
		if(' '==*pRight){
			*pNewRight--='0';
			*pNewRight--='2';
			*pNewRight--='%';
			cout<<"pNewRight:"<<pNewRight<<endl;
			--pRight;
		}else{
			*pNewRight--=*pRight--;
		}
	}
}

int main(){
	char a[]="abaccbdedff";//栈区
	char b[]="abaccbdedff";
	const char * p="abaccbdedff";
	const char * p1="abaccbdedff";//常量区
	printf("a:%p\n",a);
	printf("b:%p\n",b);
	printf("p:%p\n",p);
	printf("p1:%p\n",p1);
	
	
	char c[]=" ab a  c cb ded ff ";//栈区
//	char c[]="   ";//栈区
//	char c[]=" ";//栈区
//	char c[]="";//栈区
	char *str = (char*)new char[30]();
	cout<<str<<endl;
	strcpy(str,c);

//	char *str=NULL;
	replaceSpaceInString(str);
	printf("str:%p\n",str);
	printf("str:%s\n",str);
//	printf("str:%s\n",(char*)NULL);
	cout<<"err_no:"<<err_no<<endl;
	delete [] str;

	return 0;
}
