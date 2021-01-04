 ///
 /// @file    staticConstDataMember.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-24 10:36:21
 ///
 
#include <iostream>
using std::cout;
using std::endl;
namespace wc{
	class Student{
		public:
			Student();
			~Student();
			friend std::ostream& operator<<(std::ostream& os,const Student&);
		private:
			int _x;
			int _y;
			static const int _a=10;
			const int _b;
//			const int _b=10;//c++11
			static int _c;
//			static int _c=10;wrong
			
	};
//	const int Student::_a=10;//static const
	int Student::_c=10;//static 
	Student::Student()
	:_x(10)
	,_y(111)
//	,_a(0)//outside class
	,_b(1111)
//	,_c(0)//wrong
	{
		cout<<"Student()"<<endl;
	}

	Student::~Student() {
		cout<<"~Student()"<<endl;
	}
	std::ostream& operator<<(std::ostream& os,const Student &s){
		os<<"x:"<<s._x<<",y:"<<s._y<<",c:"<<s._c<<endl;
		return os;
	}
}
int main(){
	wc::Student s;
	wc::Student s1;

	cout<<s<<s1<<endl;
	
	return 0;
}
