//program 7.11.1.1.cpp  函数指针用法
#include <iostream>
using namespace std;
void PrintMin(int a, int b)
{
	if( a<b )
			cout << a;
	else
			cout << b;
}
int main(){
    void (* pf)(int , int);	//定义函数指针pf
    int x = 4,  y = 5;			
    pf = PrintMin;			//用PrintMin函数对指针pf进行赋值
    pf(x, y);				//调用pf指向的函数，即PrintMin
    return 0;
}

