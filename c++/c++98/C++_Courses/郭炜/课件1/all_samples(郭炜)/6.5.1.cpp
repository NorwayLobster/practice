//program 6.5.1.cpp  抽取字符串中的非中文字符
#include <iostream>
#include <cstring>
using namespace std;
int main()  
{
	cout << strlen( "中国") << endl;  //输出 4 
	char str[] = "我们都喜欢 Micheal Jackson 的歌曲\"Who's bad\"";
	for( int i = 0; str[i]; ++ i ) //抽取str中非中文的部分输出
		if( str[i] > 0) //最高位为0的字节，一定不是中文
			cout << str[i];
    return 0;
}

