 ///
 /// @file    std_filesystem.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-11-21 15:58:16
 ///
 
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <regex>  //正则表达式
//#include <experimental/filesystem>
using namespace std;
using std::string;
using std::regex;
using std::vector;
//namespace fs = std::experimental::filesystem;
namespace fs = std::filesystem;
int test1(){
	fs::path p1 = "/usr/lib/sendmail.cf"; // portable format
	std::cout << "p1 = " << p1 << '\n';
	return 0;
}


int main(){
//    string strPath = "D:\\pic\\new";
    string strPath = ".";
	vector<string> vecFilePath;


//	 fs::path p = "C:cl.exe";
	 fs::path p = strPath;
//	 For POSIX-based operating systems, std::filesystem::absolute(p) is equivalent to std::filesystem::current_path() / p except for when p is the empty path.


    std::cout << "Current path is " << fs::current_path() << '\n'
              << "Absolute path for " << p << " is " << fs::absolute(p) << '\n';
// actual location: "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\bin\cl.exe"
//    for (auto&DirectoryIter : fs::directory_iterator(strPath)){
    for (fs::directory_entry DirectoryEntry: fs::directory_iterator(strPath)){
		fs::path filepath = DirectoryEntry.path();
		fs::path filename = filepath.filename();
		cout << filename<< endl;
		cout << filename.string() << endl;
		cout << filepath<< endl;
		cout << filepath.string() << endl;
		vecFilePath.push_back(filepath.string());
	}
	for(auto s:vecFilePath){
		cout<<s<<" ";
	}
	cout<<endl;
}
