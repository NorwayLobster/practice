//program 7.14.3.cpp  单词排序解法2
#include <iostream>
using namespace std;
const int WORD_NUM = 10000;
const int WORD_LEN = 100;
char * words[WORD_NUM + 10];//数组稍微开大一点，保险
int MyCompare( const void * e1, const void * e2)
{
	char ** p1 = ( char **) e1;
	char ** p2 = ( char **) e2;
	return strcmp(*p1,*p2); //*p1和*p2指向待比较的两个单词
}
int main()  
{
	int n;
	char word[120];
	cin >> n;
	for( int i = 0;i < n;++i ) {
			cin >> word;
			words[i] = new char[strlen(word)+1];//要留出放末尾'\0'的空间
			strcpy(words[i],word);
	}
	qsort(words,n,sizeof(char *),MyCompare);
	for( int i = 0;i < n;++i ) {
			cout << words[i] << endl;
			delete [] words[i]; //不要忘了释放空间
	}
	return 0;
}

