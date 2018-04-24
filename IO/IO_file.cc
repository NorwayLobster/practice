///
/// @file    IO_file.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2018-04-24 21:04:52
///

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;

int test0(char *p)
{
	std::ifstream ifs(p);//定义并打开了一个ifstream对象
	if(!ifs.good())
	{
		std::cout << "open file error!" << std::endl;
		return -1;
	}

#if 1
	std::string s;
	//while(ifs >> s)
	//{
	//    std::cout << s <<std::endl;
	//}

	std::vector<std::string> vec_str;
	std::string line;
	while(getline(ifs, line))
	{
		//std::cout << line << std::endl;
		vec_str.push_back(line);
	}

	#if 1
	//std::vector<std::string>::iterator sit = vec_str.begin();
	auto sit=vec_str.begin();
	for(; sit != vec_str.end(); ++sit)
	{
		std::cout << *sit << std::endl;
	}
	#endif
#if 0
	for(auto &line: vec_str)
	{
		cout<<line<<endl;
	}
#endif
	//for_each(vec_str.begin(),vec_str.end(),);
	ifs.close();

#endif
	return 0;
}

int test2(void)
{

	std::ifstream ifs("io1");
	if(!ifs.good())
	{
		std::cout << "open file error!" << std::endl;
		return -1;
	}

	std::ofstream ofs("test.txt");
	if(!ofs.good())
	{
		std::cout << "open file error!" << std::endl;
		return -1;
	}
	std::string line;
	while(getline(ifs, line))
	{
		ofs << line << std::endl;
	}

	return 0;

}

int main(int argc, char** argv)
{
	if(2!=argc)
	{
		cout<<"arg error"<<endl;
	}
	test0(argv[1]);
	return 0;
}
