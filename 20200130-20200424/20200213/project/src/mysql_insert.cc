#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
//int mysql_insert(char *arg0,char *arg1,char* arg2,char * arg3,char * arg4,char *arg5)
int mysql_insert(char *query)
{
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;

	char* server="localhost";
	char* user="root";
	char* password="wc";
	char* database="cheng";//要访问的数据库名称
	//char* database="student";//要访问的数据库名称
//	char query[300]="insert into user_info(username, salt , ciphertext, user_root_dir) values('cheng','$6$4n1T28WC$',\
//							'Zzd5.ETGY4fPI97yZQqQCs9Am72jT0X4LZMCeaCRg6ALwpybcADrCAtpirJ/sh7yfGt1aBjt/AlPbKAWQEpz50:18294:0:99999:7:::'\
//							'/home/cheng/baiduwangpan/cheng')";
//	char query[300]="insert into user_info_and_virtual_filesystem(pre_dir_code , username, filename , filetype, md5sum)\
//															values(1,'cheng','test2','-','f3c4b36910e268a4d1c8dd8053d17e67')";
//	char query[300]="insert into user_info(username, salt , ciphertext, user_root_dir) values(";
//	sprintf(query,"%s'%s','%s','%s','%s')",query,arg1,arg2,arg3,arg4);
//	sprintf(query,"%s'%s','%s','%s','%s')",query,arg1,arg2,arg3,arg4);
//	strcpy(query,"select * from Person1");
//	puts(arg1);
//	puts(arg2);
//	puts(arg3);
//	puts(arg4);
//	puts(arg5);
//	puts(query);
//	_exit(1);
	int t,r;
	conn=mysql_init(NULL);
	if(!mysql_real_connect(conn,server,user,password,database,0,NULL,0))
	{
		printf("Error connecting to database:%s\n",mysql_error(conn));
		return -1;
	}else{
		printf("Connected...\n");
	}
	t=mysql_query(conn,query);
	if(t)
	{
		printf("Error making query:%s\n",mysql_error(conn));
		return -1;
	}else{
		printf("insert success\n");
	}
	mysql_close(conn);
	return 0;
}
#ifdef __MAIN__ 
int main(){
	mysql_insert("test","$6$4n1T28WC$",\
				"Zzd5.ETGY4fPI97yZQqQCs9Am72jT0X4LZMCeaCRg6ALwpybcADrCAtpirJ/sh7yfGt1aBjt/AlPbKAWQEpz50:18294:0:99999:7:::",\
							"/home/cheng/baiduwangpan/cheng","");
	return 0;
}
#endif
