 ///
 /// @file    std_move.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-09-15 22:08:02
 ///
 
#include <iostream>
using namespace std;
class Stu{
public:
	Stu(int a,int b,char * _name)
		:_x(a)
		 ,_y(b)
	{
		
		cout<<"Stu(int a,int b)"<<endl;}
	Stu(const Stu&s)
		:_x(s._x)
		 ,_y(s._y)
	{cout<<"Stu(const Stu&s)"<<endl;}
	Stu(const Stu&& s):
	:_x(	
	{
	}

	int _x;
	int _y;
	char *_name;
};
int f(Stu & s){
	vector<Stu> v;
	v.emplace(std::move(s));
}

int main(){
	Stu s(1,2);
	return 0;
}
