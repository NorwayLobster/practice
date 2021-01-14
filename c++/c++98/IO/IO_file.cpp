 ///
 /// @file    输入流的默认分隔符.cc /// @author  lemon(haohb13@gmail.com) /// @date    2018-03-30 13:55:00
 ///
 
#include <iostream>
#include <fstream>
#include <fstream>
using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::stringstream;
using std::fstream;
using std::string;
int main(int argc, char**argv)
{
	string word1,word2;
	string word3,word4;
	string word5,word6;
	fstream fs;
	if(2!=argc)
	{
		cout<<"arg error"<<endl;
		return -1;
	}
	fs.open(argv[1]);
	//fs.open("file.txt");
//	fstream fs;
//	fs.open("test");
//	if(!fs.good())
//	{
//		cerr<<"fs open error"<<endl;
////		exit(1);
//	}
////	fs.clear();
//	cout<<"fs's status is:"<<fs.good()<<endl;
//	
//	cout<<"--------------"<<endl;
////	fs>>word1>>word2;
//	//getline();
//	cout<<"1:"<<word1<<endl;
//	cout<<"--------------"<<endl;
//	cout<<"2:"<<word2<<endl;
//	cout<<"---------------------------------------------------------"<<endl;
//	
//	fs<<"hello"<<" world"<<" ";
	fs<<"hello"<<" world";
	if(!fs.good())
	{
		cerr<<"fs out error"<<endl;
		return 0;
	}
	cout<<"fs.good():"<<fs.good()<<endl;
//	fs<<"hello"<<"world"<<endl;
//	cout<<fs.str()<<endl;
	cout<<"--------------"<<endl;
#if 1
	fs>>word3>>word4;
	if(!fs.good())
	{
		cerr<<"fs in error"<<endl;
//		return 0;
	}
	cout<<"fs.good():"<<fs.good()<<endl;
	cout<<"fs.eof():"<<fs.eof()<<endl;
	cout<<"fs.bad():"<<fs.bad()<<endl;
	cout<<"fs.fail():"<<fs.fail()<<endl;
	cout<<"fs.tellg:"<<fs.tellg()<<endl;
	cout<<"--------------"<<endl;
	fs.clear();
	cout<<"fs.good():"<<fs.good()<<endl;
	cout<<"fs.eof():"<<fs.eof()<<endl;
	cout<<"fs.bad():"<<fs.bad()<<endl;
	cout<<"fs.fail():"<<fs.fail()<<endl;
	cout<<"fs.tellg:"<<fs.tellg()<<endl;
	cout<<"--------------"<<endl;
	fs.seekg(std::ios::beg);
	cout<<"fs.good():"<<fs.good()<<endl;
	cout<<"fs.eof():"<<fs.eof()<<endl;
	cout<<"fs.bad():"<<fs.bad()<<endl;
	cout<<"fs.fail():"<<fs.fail()<<endl;
	cout<<"fs.tellg:"<<fs.tellg()<<endl;
	cout<<"--------------"<<endl;
#if 0
	fs>>word3>>word4;
	cout<<"fs.good():"<<fs.good()<<endl;
	cout<<"fs.eof():"<<fs.eof()<<endl;
	cout<<"fs.bad():"<<fs.bad()<<endl;
	cout<<"fs.fail():"<<fs.fail()<<endl;
#endif

	cout<<"3:"<<word3<<endl;
	cout<<"4:"<<word4<<endl;
	cout<<"--------------"<<endl;

	//fs<<" i am cheng"<<" wang";
	//fs<<" i am cheng"<<" wang"<<" ";
	//cout<<"str():"<<fs.str()<<endl;
	cout<<"fs.good():"<<fs.good()<<endl;
	cout<<"--------------"<<endl;

	fs>>word5>>word6;
	cout<<"5:"<<word5<<endl;
	cout<<"6:"<<word6<<endl;
	cout<<"fs.good():"<<fs.good()<<endl;
	cout<<"fs.eof():"<<fs.eof()<<endl;
	cout<<"fs.bad():"<<fs.bad()<<endl;
	cout<<"fs.fail():"<<fs.fail()<<endl;
	cout<<"fs.tellg:"<<fs.tellg()<<endl;
	cout<<"--------------"<<endl;
#endif

}
