#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
int main(int argc,char* argv[])
{
	if(argc!=1)
	{
		printf("error args\n");
		return -1;
	}
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;

	char* server="localhost";
	char* user="root";
	char* password="wc";
	char* database="cheng";//要访问的数据库名称
	//char* database="student";//要访问的数据库名称
	char query[300]="create table virtual_filesystem(cur_dir_code int NOT NULL AUTO_INCREMENT, PRIMARY KEY(cur_dir_code),\
					 pre_dir_code int, username varchar(20), constraint username_FK foreign key(username) references user_info(username),\
					 filename varchar(20), filetype varchar(2), md5sum varchar(128))";
//	sprintf(query,"%s%s%s",query,argv[1],"'");
//	strcpy(query,"select * from Person1");
	puts(query);
	int t,r;
	conn=mysql_init(NULL);
	if(!mysql_real_connect(conn,server,user,password,database,0,NULL,0))
	{
		printf("Error connecting to database:%s\n",mysql_error(conn));
	}else{
		printf("Connected...\n");
	}
	t=mysql_query(conn,query);
	if(t)
	{
		printf("Error making query:%s\n",mysql_error(conn));
	}else{
		printf("create success\n");
	}
	mysql_close(conn);
	return 0;
}
