//program 7.14.4.cpp 单词排序解法三
#include <iostream>
#include <string>    //要使用string对象必须包含此头文件
#include <algorithm> //要使用排序算法sort 必须包含此头文件
using namespace std;
const int WORD_NUM = 10000;
string words[WORD_NUM + 10];
int main()  
{
	int n;
	cin >> n;
	for( int i = 0;i < n;++i ) 
		cin >> words[i]; //words每个元素存放一个单词
	sort(words,words+n); //调用C++标准模板sort进行排序
	for( int i = 0;i < n;++i ) 
		cout << words[i] << endl;
	return 0;
}

