 ///
 /// @file    输入流的默认分隔符.cc /// @author  lemon(haohb13@gmail.com) /// @date    2018-03-30 13:55:00
 ///
 
#include <iostream>
#include <sstream>
#include <fstream>
using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::stringstream;
using std::fstream;
using std::string;
int main(void)
{
	string word1,word2;
	string word3,word4;
	string word5,word6;
	stringstream ss;
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
//	ss<<"hello"<<" world"<<" ";
	ss<<"hello"<<" world";
	cout<<"ss.good():"<<ss.good()<<endl;
//	ss<<"hello"<<"world"<<endl;
	cout<<ss.str()<<endl;
	cout<<"--------------"<<endl;
#if 1
	ss>>word3>>word4;
	cout<<"ss.good():"<<ss.good()<<endl;
	cout<<"ss.eof():"<<ss.eof()<<endl;
	cout<<"ss.bad():"<<ss.bad()<<endl;
	cout<<"ss.fail():"<<ss.fail()<<endl;
	cout<<"ss.tellg:"<<ss.tellg()<<endl;
	cout<<"--------------"<<endl;
	ss.clear();
	cout<<"ss.good():"<<ss.good()<<endl;
	cout<<"ss.eof():"<<ss.eof()<<endl;
	cout<<"ss.bad():"<<ss.bad()<<endl;
	cout<<"ss.fail():"<<ss.fail()<<endl;
	cout<<"ss.tellg:"<<ss.tellg()<<endl;
	cout<<"--------------"<<endl;
	ss.seekg(std::ios::beg);
	cout<<"ss.good():"<<ss.good()<<endl;
	cout<<"ss.eof():"<<ss.eof()<<endl;
	cout<<"ss.bad():"<<ss.bad()<<endl;
	cout<<"ss.fail():"<<ss.fail()<<endl;
	cout<<"ss.tellg:"<<ss.tellg()<<endl;
	cout<<"--------------"<<endl;
#if 0
	ss>>word3>>word4;
	cout<<"ss.good():"<<ss.good()<<endl;
	cout<<"ss.eof():"<<ss.eof()<<endl;
	cout<<"ss.bad():"<<ss.bad()<<endl;
	cout<<"ss.fail():"<<ss.fail()<<endl;
#endif

	cout<<"3:"<<word3<<endl;
	cout<<"4:"<<word4<<endl;
	cout<<"--------------"<<endl;

	ss<<" i am cheng"<<" wang";
	//ss<<" i am cheng"<<" wang"<<" ";
	cout<<"str():"<<ss.str()<<endl;
	cout<<"ss.good():"<<ss.good()<<endl;
	cout<<"--------------"<<endl;

	ss>>word5>>word6;
	cout<<"5:"<<word5<<endl;
	cout<<"6:"<<word6<<endl;
	cout<<"ss.good():"<<ss.good()<<endl;
	cout<<"ss.eof():"<<ss.eof()<<endl;
	cout<<"ss.bad():"<<ss.bad()<<endl;
	cout<<"ss.fail():"<<ss.fail()<<endl;
	cout<<"ss.tellg:"<<ss.tellg()<<endl;
	cout<<"--------------"<<endl;
#endif

}
