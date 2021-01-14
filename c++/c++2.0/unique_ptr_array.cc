 ///
 /// @file    unique_ptr_array.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-05-11 23:14:31
 ///
 
// g++ unique_ptr_array.cc -std=c++11 -fno-elide-constructors

#include <bits/stdc++.h>
using namespace std;
class Student{
	public:
		Student(){cout<<"ctor()"<<endl;}
		Student(int i,int j)
			:_x(i)
			,_y(j)
		{cout<<"ctor(int,int)"<<endl;}
		~Student() {cout<<"dtor()"<<endl;}

		int _x;
		int _y;
};
int main(){
//1. unique_ptr 托管动态数组, 维度是数组类型的一部分
//	unique_ptr<int[]> up(new int[10]);	
	unique_ptr<Student[]> up(new Student[10]);	
	for(int i=0;i<10;i++){
		up[i]=Student(i,i+1);
		cout<<"up["<<i<<"]="<<up[i]._x<<","<<up[i]._y<<endl;
	}

//2. up.relase()
//	auto p=up.release();//释放托管所有权，释放后需要自己手动释放
//	delete [] p;

	cout<<endl<<endl;
// 3.  shared_ptr托管动态数组，提供deleter
	 shared_ptr<Student> sp(new Student[10],[](Student *p)->void{delete [] p;});
	 
	return 0;
}
