//program 12.1.3.2.cpp  非默认复制构造函数
#include <iostream>
using namespace std;
class Complex {
	public :
 		double real,imag;
		Complex(double r,double i){
  		    real = r;  imag = i;
		}
		Complex( Complex & c ) {
             real = c.real;  imag = c.imag;
		    cout << "Copy Constructor called" << endl;
	}
}; 
int main(){
	Complex c1(1,2);
	Complex c2(c1); //调用复制构造函数
	cout << c2.real << "," << c2.imag ;
	return 0;
}

