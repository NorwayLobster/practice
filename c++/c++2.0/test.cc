 ///
 /// @file    test.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-05-07 06:46:12
 ///
 
#include <iostream>
#include <cstdio>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
class Student{
private:
	int a;
	long int b;
};
void print(){ cout<<"void()"<<endl; }
//note: 只有返回值type is different, can not be overload
//int print(){ cout<<"void()"<<endl; }
int print(int x){ cout<<"int(int)"<<endl; return x;}
extern "C" double print(double x){ printf("double(double)\n"); return x;}
//extern "C" float print(float x,float y){ printf("float(float)\n"); return x;}
int main(){
	Student s;
	vector<vector<int>> v;
	v.push_back(vector<int> {1,3,2});

	cout<<"sizeof(int):"<<sizeof(int)<<endl;
	cout<<"sizeof(long int):"<<sizeof(long int)<<endl;
	cout<<"sizeof(Student):"<<sizeof(s)<<endl;
	cout<<"sizeof(Student):"<<sizeof(Student)<<endl;
	print(10);
	print(10.13);
	print();

	return 0;
}
