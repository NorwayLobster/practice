//program 7.14.2.1.cpp  用二进制文件保存学生记录
#include <iostream>
#include <fstream>
using namespace std;
class CStudent 
{
	public:
		char szName[20];
		int age;
};
int main()
{
	CStudent s;		
	ofstream outFile("students.dat",ios::out|ios::binary);
	while( cin >> s.szName >> s.age ) 
		outFile.write( (char *) & s, sizeof(s));
	outFile.close();
	return 0;
}

