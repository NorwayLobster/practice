//program 19.13.3.cpp  用STL算法操作string对象
#include <iostream>
#include <algorithm>
#include <string> 
using namespace std;
int main()  
{
   string s("afgcbed");
   string::iterator p = find(s.begin(),s.end(),'c');
   if( p != s.end())
	   	cout << p - s.begin() << endl; //输出 3
   sort(s.begin(),s.end());
   cout << s << endl; //输出 abcdefg
   next_permutation(s.begin(),s.end());
   cout << s << endl; //输出 abcdegf
   return 0;
}

