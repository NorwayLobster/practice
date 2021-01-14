//program 20.6.3.1.cpp 正则表达式
#include <iostream>
#include <regex> //使用正则表达式须包含此文件
using namespace std;
int main()
{
	regex reg("b.?p.*k");
	cout << regex_match("bopggk",reg) <<endl;
	cout << regex_match("boopgggk",reg) <<endl;
	cout << regex_match("b pk",reg) <<endl;
	regex reg2("\\d{3}([a-zA-Z]+).(\\d{2}|N/A)\\s\\1"); 
	string correct="123Hello N/A Hello";
	string incorrect="123Hello 12 hello"; 
	cout << regex_match(correct,reg2) <<endl;
	cout << regex_match(incorrect,reg2) << endl;
}
/*
. 代表任意一个字符
*  重复零次或更多次
+ 重复一次或更多次
?  重复零次或一次
*/
