//program 3.9.1.cpp  freopen用法示例
#include <iostream>
using namespace std;
int main()
{
 	freopen("c:\\tmp\\test.txt","r",stdin); // 字符串中的"\"要写两次 
	int n;
	cin >> n;
	while( n -- ) {
		   int a,b;
		   cin >> a >> b;
		   cout << (a>b?a:b) << endl;
    }
}

