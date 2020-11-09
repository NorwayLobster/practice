///
/// @file    string.h
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-23 14:05:41
///
#ifndef __STRING__H__
#define __STRING__H__
#include <iostream>
using std::cout;
using std::endl;
class String
{
	public:
		String();
		String(const char *pstr);
		String(const String & rhs);
		String & operator=(const String & rhs);
		~String();

		void print();

	private:
		char * _pstr;
};

#endif
