 ///
 /// @file    specialMemberInit.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-23 16:15:55
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Point{
	public:
		Point();
		Point(int,int);
		Point(const Point &);
		Point & operator=(const Point &);
		~Point();
		void print();
		void print() const;
		static void print_num();
	private:
		static int _num;
		const int _x;
		int _y;
		int & _ref;
};

