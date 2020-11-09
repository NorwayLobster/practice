#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <head.hpp>
//int main(int argc,char* argv[])
int mysql_query_my(char * query,char** query_result)
{
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;

	char* server="localhost";
	char* user="root";
	char* password="wc";
	char* database="cheng";//要访问的数据库名称
	//char* database="student";//要访问的数据库名称
//	sprintf(query,"%s%s%s",query,argv[1],"'");
//	strcpy(query,"select * from virtual_filesystem");
	puts(query);
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

	int i=0;
	printf("t:%d\n",t);
	if(t)
	{
		printf("Error making query:%s\n",mysql_error(conn));
		return -1;
	}else{
	//	printf("Query made...\n");
		res=mysql_use_result(conn);
		if(res)
		{

			while((row=mysql_fetch_row(res))!=NULL)
			{	
				query_result[i]=(char*)calloc(256,sizeof(char));
				printf("num=%d\n",mysql_num_fields(res));//列数
				for(t=0;t<mysql_num_fields(res);t++)
				{
						sprintf(query_result[i],"%s %s ",query_result[i],row[t]);
				}
				puts(query_result[i]);
				++i;//几条记录,
				printf("\n");
			}
		}
		mysql_free_result(res);
	}
	mysql_close(conn);
	return i;//query 的行数即记录条数
}
#ifdef __MAIN__
int main(){

	char query[300]={0};
//	strcpy(query,"select * from user_info");
	strcpy(query,"select cur_dir_code from virtual_filesystem where username='luke' and pre_dir_code=3 and filename='dir3'");

	char *query_result[32]={0};//查询结果最多支持32条记录
	int ret=0;
	ret=mysql_query_my(query,query_result);

	printf("ret:%d\n",ret);
	int i=0;	
	char *p=query_result[i];
	printf("addr:%p\n",query_result[i]);
	while(NULL!=p) {
			puts(query_result[i]);
			free(query_result[i]);
			p=query_result[++i];
			printf("addr:%p\n",query_result[i]);
		//	++i;
	}
	return 0;
}	

#endif
