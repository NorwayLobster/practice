//program 7.9.2.1.cpp  string对象和char*指针关系
#include <iostream>
#include <cstring> 
#include <string>
using namespace std;
int main()  
{
	string s;
	char str1[20] = "The Flowers Of War";
	char str2[20] = ""; //str2是空串
	char * p = str1; 
	s = p; // s 变成 "The Flowers Of War"
	strcat(str2,s.c_str()); //将s的内容连接到str2
	cout << str2 << endl;   //输出  The Flowers Of War
	return 0;
}

