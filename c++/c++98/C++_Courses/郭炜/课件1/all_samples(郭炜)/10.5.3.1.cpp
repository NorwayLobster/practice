//program 10.5.3.1.cpp  ЬѕМўБрвы
#include <iostream>
#include <string>
using namespace std;
#define LINUX 
int main()
{
#ifdef LINUX
	string msg = "Your Linux version is too old";
#else
	string msg = "Your Windows version is too old";
#endif
	cout << msg << endl;
#ifdef DEBUG
	cout << "this is debug version" << endl;
#endif
	return 0;
}

