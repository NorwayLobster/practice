//program 16.5.2.2.cpp  用cin.getline读取文件全部内容
#include <iostream>
using namespace std;
const int MAX_LINE_LEN = 10000;   //假设文件中一行最长10000个字符
int main()
{
 	char szBuf[MAX_LINE_LEN + 10]; 
 	freopen("test.txt","r",stdin);   //将标准输入重定向为test.txt 
 	while(cin.getline(szBuf,MAX_LINE_LEN + 5)) 
			 cout << szBuf << endl;
    return 0;
}
