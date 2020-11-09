 ///
 /// @file    Computer.h
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-23 12:53:14
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Computer{
public:
	Computer(){}
	Computer(const char * brand, double price,double weight);
	Computer(const char * brand, double price,double weight,double age);
	Computer(const char * brand, double price);
	Computer(const Computer & c);
	void print();
	void setBrand(char * brand, double price);
	~Computer();
private:
	char * _brand;
	//char _brand[20];
	double _price;
	double _weight;
	double _age;
};
