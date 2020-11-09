 ///
 /// @file    myhash.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-05-08 11:02:45
 ///
 
#include <iostream>
#include <bits/stdc++.h>
using std::cout;
using std::endl;
using namespace std;
class StudentHash;
class Student{
	public:
		Student(int a,string name)
			:_x(a)
			 ,_y(name)
	{cout<<"Student(int,string)"<<endl;}
		~Student() {cout<<"~Student()"<<endl;}
	 friend bool operator==(const Student&lhs,const Student &rhs);
	 friend class StudentHash;
		int _x;
		string _y;
};

bool operator==(const Student&lhs,const Student &rhs) {
	cout<<"operator==()"<<endl;
	return lhs._x==rhs._x&&lhs._y==rhs._y;
}
class StudentHash{
	public:
	//	size_t operator()(const Student&s){//error: 必须是const
	size_t operator()(const Student&s)const{
		cout<<"operator()()"<<endl;
		return std::hash<int>()(s._x)^std::hash<string>()(s._y);
	}
};
int main(){
	unordered_map<Student,string,StudentHash> hash;
	Student s(1,"cheng");
	hash[s]=string("23");
	cout<<hash.size()<<endl;
	cout<<hash[s]<<endl;
	cout<<endl<<endl;
	return 0;
}
