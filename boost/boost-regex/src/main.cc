/*
 * @Author: your name
 * @Date: 2020-11-17 20:14:50
 * @LastEditTime: 2020-11-17 22:08:08
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /practice/boost-regex/src/main.cc
 */
 ///
 /// @file    main.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-11-17 20:13:31
 ///
 
#include <iostream>
#include <string>
#include <boost/regex.hpp>
using namespace std;

int main(){
	string iContent;
	string szReg = "<.*?>";
	boost::regex fmt(szReg);
	string content=boost::regex_replace(string(iContent),fmt,string(""));
	return 0;
}
