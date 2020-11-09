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
	char query[300]="create table user_info(username varchar(20) NOT NULL , PRIMARY KEY(username), salt varchar(20),\
					 ciphertext varchar(128), user_root_dir varchar(128))";
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
