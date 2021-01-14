 ///
 /// @file    testMain.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-23 16:29:27
 ///
 
#include <iostream>
#include "specialMemberInit.h"
using std::cout;
using std::endl;
int main(){
	
	Point p(1,23); p.print();
	p.print_num();

	cout<<endl;

	Point p1(11,2);
	p1.print();
	p1.print_num();

	cout<<endl;
	p1.print_num();
cout<<endl;
//3. 通过类名调用
	Point::print_num();

//4 
	const Point p2(1,23);
	p2.print();
	return 0;

}
