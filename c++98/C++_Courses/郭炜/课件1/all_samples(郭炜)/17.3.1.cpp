//program 17.3.1.cpp  用流类的构造函数打开文件
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
 	ifstream inFile;
    inFile.open( "c:\\tmp\\test.txt",ios::in);
 	if(inFile) //条件成立则说明文件打开成功
    		inFile.close();
     else
   		cout << "test.txt doesn't exist" << endl;
	ofstream oFile;
	oFile.open( "test1.txt", ios::out);
	if( !oFile) //条件成立则说明文件打开出错
		cout << "error 1" << endl;
	else
		oFile.close();
	oFile.open( "tmp\\test2.txt",ios::out | ios::in);
	if( oFile) //条件成立则说明文件打开成功
		oFile.close();
	else
		cout << "error 2" << endl;
	fstream ioFile;
    ioFile.open( "..\\test3.txt", ios::out | ios::in | ios::trunc );
	if(!ioFile)
		cout << "error 3" << endl;		
	else
		ioFile.close();
	return 0;
}

