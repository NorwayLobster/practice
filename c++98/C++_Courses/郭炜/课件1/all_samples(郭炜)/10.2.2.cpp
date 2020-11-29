//program 10.2.2.cpp  静态局部变量应用
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
bool GetWord(const char * str,char * word)
{
	static const char * p; //本次单词的寻找起点
	int i;
	if( str ) //str不为空，说明要在一个新的字符串里找单词
		p = str;
	for( i = 0; !isalpha(p[i]) && p[i]; ++ i) ;//找第一个字母,isalpha是库函数
	if( p[i] == 0 ) //已经到了结尾的'\0'，说明没有单词了
		return false;
	p +=  i; //走到这说明找到字母了,让p指向单词的起始位置
	for( i = 0;isalpha(p[i]) && p[i]; ++ i) ;//找下一个分隔字符
	strncpy(word,p,i); //拷贝单词
	word[i] = 0;  //添加单词末尾的 '\0'
	p += i; //将p设为下一个单词的寻找起点
	return true;
}
int main()
{
	char * sentence = "To be or not to be,is a problem.";
	char word[100]; //假设单词长度不会超过99
 	bool b = GetWord( sentence,word );//从sentence中取下一个单词，放入word
	while( b ) { //GetWord返回值为true说明取出了单词，为false说明已无单词可取
		cout << word << endl;
		b = GetWord(NULL,word);
	}
}

