 ///
 /// @file    string_cow.hpp
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-21 13:40:09
 ///
#ifndef _String_HPP_ 
#define _String_HPP_ 
#include <iostream>
using std::cout;
using std::endl;
class String{
public:
	String();
	String(const char*p);
	String(const String&);
	String&operator=(const String&);
	//	std::move();

	~String();

private:

};
#endif
