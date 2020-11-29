//program 19.13.1.cpp string类的查找成员函数
#include <iostream>
#include <string> 
using namespace std;
int main()  
{
	string s1("Source Code");
	int n;
	if( (n = s1.find('u')) != string::npos ) //查找u出现的位置
		cout <<"1) "<< n << "," << s1.substr (n) << endl;  //输出 1) 2,urce Code 
	if( (n = s1.find("Source", 3)) == string::npos ) //从下标3开始查找"Source",找不到
		cout <<"2) "<< "Not Found" << endl;   //输出 2) Not Found
	if(( n = s1.find("Co")) != string::npos )  //查找子串 "Co",能找到，返回"Co"位置
		cout <<"3) "<< n << ","<< s1.substr(n) << endl; //输出 3) 7,Code
	if( (n = s1.find_first_of("ceo")) != string::npos )
         //查找第一次出现了'c'或'e'或'o'的位置
		cout <<"4) "<< n << ","<< s1.substr(n) << endl; //输出 4) 1,ource Code
	if( (n = s1.find_last_of('e')) != string::npos )     //查找最后一个'e'的位置
		cout <<"5) "<< n << ","<< s1.substr(n)<< endl;  //输出 5) 10,e
	if( (n = s1.find_first_not_of("eou",1)) != string::npos) 	
         //从下标1开始查找第一次出现非'e'非'o'非'u'字符的位置
		cout <<"6) "<< n << ","<< s1.substr(n)<< endl;  //输出 6) 3,rce Code
	return 0;
}

