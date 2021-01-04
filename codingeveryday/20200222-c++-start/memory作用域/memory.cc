 ///
 /// @file    memory.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-23 02:37:40
 ///
 
#include <cstdio>
int a_global;//全局非静态，
static int a_global_static;//全局静态,只在本.cc文件有效，static限制其在他文件的可见性
int a_global_not_init;//全局非静态变量 未初始化
int a_global_init=10;//全局非静态变量 初始化
char *p_global;
const int c_global=100;
char *p_new_global=new char[10];
void test(){
	int a=10;
	int*p;
	 char str[]="hello";//栈区
	const char *p_str="hello";//常量区
	static int a_local_static=10;	//只初始化一次
	++a_local_static;
	char *p_new=new char[10];
	const int c=10;
	printf("&a:%p\n",&a);
	printf("&a_global_static:%p\n",&a_global_static);

	printf("&a_global:%p\n",&a_global);
	printf("&a_global_not_static_init:%p\n",&a_global_init);
	printf("&a_global_not_static_not_init:%p\n",&a_global_not_init);

	printf("&a_local_static:%p\n",&a_local_static);
	printf("a_local_static:%d\n",a_local_static);

	printf("&p:%p\n",&p);
	printf("p:%p\n",p);
	printf("&p_global:%p\n",&p_global);
	printf("p_global:%p\n",p_global);
	printf("&str:%p\n",&str);
	printf("str:%p\n",str);
	printf("&p_str:%p\n",&p_str);
	printf("p_str:%p\n",p_str);
	printf("hello's address:%p\n","hello");
	printf("p_new:%p\n",p_new);
	printf("&p_new:%p\n",&p_new);
	printf("p_new_global:%p\n",p_new_global);
	printf("&p_new_global:%p\n",&p_new_global);
	printf("&c:%p\n",&c);
	printf("&c_global:%p\n",&c_global);
	printf("\n");

}
int main(){
	test();
	test();
	return 0;
}

