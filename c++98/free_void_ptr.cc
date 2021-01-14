 ///
 /// @file    free_void_ptr.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2021-01-14 11:28:28
 ///
 
#include <iostream>
using namespace std;
class Student{
	public:
		int age;
		int height;
		Student(){
			cout<<"ctor"<<endl;
		}
		~Student(){
			cout<<"dtor"<<endl;
		}
	
};
int main(){
	Student* pnew = new Student();		
	Student* pnew1 =(Student*)malloc(sizeof(Student));		
	pnew->age=1;
	pnew->age=11;

	pnew1->age=13;
	pnew1->age=15;
	cout<<pnew->age<<endl;
	cout<<pnew1->age<<endl;
	delete pnew;
	void * p=malloc(10*sizeof(int));
	free(pnew1);
	free(p);
	free(NULL);
//	delete nullptr;// compile error
//	delete NULL;// compile error
	return 0;
}
