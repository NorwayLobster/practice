//program 7.14.2.cpp  单词排序解法1
#include <iostream>
#include <cstring>
using namespace std;
const  int WORD_NUM  = 10000;
const int  WORD_LEN = 100;
char words[WORD_NUM + 10][WORD_LEN+10];
//数组稍微开大一点没坏处,免得由于边界处理不好导致出错
int MyCompare( const void * e1, const void * e2)
{
	char * str1 = ( char *) e1;//str1会指向一个单词
	char * str2 = ( char *) e2;//str2会指向一个单词
	return strcmp(str1,str2);//strcmp是字符串比较库函数
}
int main()  
{
	int n;
	cin >> n;
	for( int i = 0;i < n;++i ) 
			cin >> words[i]; //words每行存放一个单词
	qsort(words,n,sizeof(words[0]),MyCompare);
	for( int i = 0;i < n;++i ) 
			cout << words[i] << endl;
	return 0;
}

