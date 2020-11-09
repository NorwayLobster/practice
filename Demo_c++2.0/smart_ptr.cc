 ///
 /// @file    smart_ptr.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-07-10 13:14:41
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
class Stu{
	public:
		Stu(){cout<<"Stu()"<<endl;}
		Stu(int a,int b)
		:_x(a)
		,_y(b)
		{cout<<"Stu()"<<endl;}
		Stu(const Stu& s){}
		Stu & operator=(const Stu& s){ }

		Stu(Stu&& s){}
		Stu & operator=(const Stu&&s){
			if(this!=&s){
			}
			return *this;
		}
		~Stu(){cout<<"~Stu()"<<endl;}
	private:
		int _x;
		int _y;
};
int main(){
	std::shared_ptr<Stu> p(new Stu(10,1));
	std::shared_ptr<Stu> p1=p;
	std::shared_ptr<Stu> p2(p);
	cout<<endl;

	std::shared_ptr<Stu> p3=std::make_shared<Stu>(10,11);
	return 0;
}
