 ///
 /// @file    sizeof.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2021-01-14 14:25:28
 ///
 
#include <iostream>
using namespace std;
class MyClass
{};

void Foo(char buffInput[100]){

    char buffName[] = "hello";

    char* pChar = buffName;

    int iValue = 10;

    MyClass hMyClass;

    int a = sizeof(buffName);// 6 bytes
    int b = sizeof(pChar); //32bit: 4 bytes, 64bit: 8 bytes
    int c = sizeof(iValue); //4 bytes
    int d = sizeof(buffInput); //100 bytes
    int e = sizeof(hMyClass); //1 bytes
    printf("a=%d,b=%d,c=%d,d=%d,e=%d", a, b, c, d, e);
}

int main(){
	char buff[100];
	Foo(buff);
	return 0;
}
