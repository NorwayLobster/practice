 ///
 /// @file    regex.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-11-22 11:33:56
 ///
 
#include <iostream>
#include <regex>
using namespace std;
int main(){
	//TODO
    regex fileSuffix("(.*)(.jpg)");// *.jpg, *.png
    //regex fileSuffix("(.*).(.jpg)"); 也行
    //regex fileSuffix(".*z.*\\.(jpg|png)");//包含字母z的所有jpg或png图片
	if (std::regex_match(filename.string(), fileSuffix)){
		cout << filepath << endl;
	}
	//replace_extension替换扩展名
	//stem去掉扩展名
	//
}	
