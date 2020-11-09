 ///
 /// @file    main.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-22 21:16:47
 ///
 
#include <iostream>
#include "OverloadOperator.h"
using std::cout;
using std::endl;
int main(){
	wc::Complex c(1,2);
	wc::Complex c1(11,22);
	c.display();
	c1.display();
	wc::Complex c3=c+c1;
	c3.display();
	wc::Complex c4=c3++;

	cout<<endl;
	c3.display();
	c4.display();
	
	cout<<endl;
	(++c).display();
	c.display();
	cout<<endl;
//
//	wc::Complex c5=1+c; error //operator+(1,c)// free func
	wc::Complex c6=c+1;//c.operator+(1);// member func
	wc::Complex c7=1;
   // c5.display();
    c6.display();
    c7.display();

	return 0;
}
