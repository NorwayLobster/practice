//program 6.4.5.1.cpp  string 基本用法
#include <iostream>
#include <string> //要使用string对象必须包含此头文件
using namespace std;
int main()  
{
	string s1 = "123",s2; // s2是空串
	s2 += s1;             // s1 = "223"
	s1 = "abc";		   // s1 = "abc"
	s1 += "def";		   // s1 = "abcdef"
	cout << "1) " << s1 << endl;  //输出 1) abcdef 
	if( s2 < s1 )
		cout << "2) s2 < s1" <<endl;
	else
		cout << "2) s2 >= s1" <<endl;
	s2[1] = 'A';	       // s2 = "1A3"
	s1 = "XYZ" + s2;	  // s1 = "XYZ1A3";
	string s3 = s1 + s2; // s3 = "XYZ1A31A3"
	cout << "3) " << s3 << endl;  //输出 3) XYZ1A31A3
	cout << "4) " << s3.size() << endl;  //求s3长度，输出 4) 9 
	string s4 = s3.substr(1,3);   //求s3从下标1开始，长度为3的子串
	cout << "5) " << s4 << endl;  //输出 5) YZ1
	char str[20];
	strcpy( str,s4.c_str());      //拷贝s4中的字符串到str
	cout << "6) " << str << endl; //输出 6) YZ1
	return 0;
}

