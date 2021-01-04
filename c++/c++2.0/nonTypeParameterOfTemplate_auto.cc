 ///
 /// @file    nonTypeParameterOfTemplate_auto.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-08-05 00:09:31
 ///
 
#include <iostream>
#include <string>
#include <vector>
using  namespace std;
template<typename T, int value>
//template<typename T, auto value>
class Stu{
public:
	Stu()=default;
	~Stu()=default;
	void print(){ cout<<"value:"<<value<<endl;}
private:
	vector<T> _v;//无法指定容器大小
};

int main(){
	Stu<string,10> s;
	s.print();

	return 0;
}
