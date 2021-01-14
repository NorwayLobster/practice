///
/// @file    word_statistics.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2018-04-24 16:23:06
///

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::fstream;
#if 0
class WordStatistic
{
public:
	WordStatistic();
	~WordStatistic();
		//......
	void readFile(const std::string & filename);
	void writeFile(const std::string &filename);
private:
	std::map<string,int> _m1;
	std::vector<string> _vec_string;
		//......
};
WordStatistic::WordStatistic()
:m1(std::make_pair<string,int>("hello",2))
{
	cout<<"WordStatistic ctor"<<endl;
}
class loadConfiguration
{
public:
	void load();
}
void WordStatistic::writeFile(const string &filename)
{
	int ret= ::write(filename, &m1,sizeof(m1));//??
	if(-1==ret)
	{
		cout<<"write error"<<endl;
	}
}
#endif

void test(const char *filename)
//void test(const string &filename)
{
	std::fstream fs(filename);
	//fs.open(0);
//	std::ofstream ofs(filename);
//	std::ifstream ifs(filename);
//	char *p =new string(1024);
	int  *p1 =new int(1024);
	///::calloc(p1,1024);

//	int ret= ::write(filename,p1,sizeof(int)*1024);//??
	fs<<p1<<endl;
//	fs>>p1;
	string s;
	fs>>s;
	if(fs.eof())
	{
		cout<<"write error"<<endl;
	}
	cout<<"file.txt:"<<p1<<endl;
	cout<<"file.txt:"<<s<<endl;
}
int main(int argc, char*argv[])
{
//	WordStatistic ws;
	if(2!=argc)
	{
		cout<<"arg error"<<endl;
	}
	
	test(argv[1]);		
	//test(string(argv[1]));		
	//test("./file.txt");		

	return 0;
}


