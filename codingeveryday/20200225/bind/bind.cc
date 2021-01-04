 ///
 /// @file    bind.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-25 23:15:10
 ///
 
#include <iostream>
#include <functional>
using std::cout;
using std::endl;

//void()
void print(){
	cout<<"print()"<<endl;
}
//int(int,int)
int add(int x, int y){
	return x+y;
}
class Task{
public:
	int doTask(int,int);
	Task(){cout<<"Task()"<<endl;}
	Task(const Task & t)
	:_x(t._x)
	,_y(t._y)
	{
		cout<<"Task(const Task & t)"<<endl;
	}
	Task operator=(const Task & t){
		return t;
	}

	~Task(){cout<<"~Task()"<<endl;}
private:
	int _x;
	int _y;
};
int Task::doTask(int x, int y){

	cout<<"doTask()"<<endl;
	cout<<"before:x:"<<x<<",y="<<y<<endl;
	x=-1;	
	cout<<"after:x:"<<x<<",y="<<y<<endl;
	return x+y;
}
typedef void (*Function)();
int main(){
	Function f1=print;	
	f1();
	auto f2=add;	
	cout<<"f2():"<<f2(10,2)<<endl;
//1.std::bind()函数模板
	auto f3=std::bind(add,10,4);
	cout<<"f3():"<<f3()<<endl;

	auto f4=std::bind(add,10,std::placeholders::_1);
	cout<<"f4():"<<f4(23)<<endl;

	auto f5=std::bind(add,10,std::placeholders::_3);
	cout<<"f5():"<<f5(23,20,100)<<endl;

	Task t;

#if 0
	auto f6=std::bind(&Task::doTask,Task(),std::placeholders::_1,std::placeholders::_3);
	cout<<"f6():"<<f6(23,20,100)<<endl;
	cout<<"------------"<<endl;

#endif
//note note: 成员函数的入口地址为&Task::doTask
//			 普通函数的入口地址为函数名字
//2.传对象, bind()的参数是值传递
//	auto f7=std::bind(&Task::doTask,t,std::placeholders::_1,std::placeholders::_3);
//	cout<<"f7():"<<f7(23,20,100)<<endl;
	auto f7=std::bind(&Task::doTask,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3);
//3.对象的地址或对象，可以在bind时传，也可以在调用时传
	cout<<"f7():"<<f7(t,23,20,100)<<endl;
	cout<<"------------"<<endl;

	auto f8=std::bind(&Task::doTask,std::move(t),std::placeholders::_1,std::placeholders::_3);
	cout<<"f8():"<<f8(23,20,100)<<endl;

	cout<<"------------"<<endl;
//4.传对象地址
	auto f9=std::bind(&Task::doTask,&t,std::placeholders::_1,std::placeholders::_3);
	cout<<"f9():"<<f9(23,20,100)<<endl;

//5.std::function 函数类型容器，类模板
	std::function<int(Task,int,int)> f10=std::bind(&Task::doTask,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3);
	cout<<"f10():"<<f10(t,23,20)<<endl;
//6. 函数占位符，会影响 返回的 函数类型
	std::function<int(Task*,int)> f11=std::bind(&Task::doTask,std::placeholders::_1,1222,std::placeholders::_2);
	cout<<"f11():"<<f11(&t,100)<<endl;

//7.  std::cref(): 传递引用
	int x=1222;
	std::function<int(Task*,int,int)> f12=std::bind(&Task::doTask,std::placeholders::_1,std::placeholders::_3,std::placeholders::_2);
	cout<<"x:"<<x<<endl;
	cout<<"f12():"<<f12(&t,100,std::cref(x))<<endl;
//?????  在函数体里改变x的值，却没有使x改变？？
	cout<<"changed:x:"<<x<<endl;

//8.  std::cref(): 传递引用
//9  注册回调函数
	std::function<int(Task*)> f13=std::bind(&Task::doTask,std::placeholders::_1,std::cref(x),x);
	x=3222;
	cout<<"x:"<<x<<endl;
//10  执行回调函数
	cout<<"f13():"<<f13(&t)<<endl;
	cout<<"changed:x:"<<x<<endl;
	cout<<"------------"<<endl;

	return 0;
}

