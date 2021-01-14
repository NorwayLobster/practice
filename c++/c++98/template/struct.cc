 ///
 /// @file    struct.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-11-26 12:37:37
 ///
 
#include <iostream>
#include <string>
#include <memory>
//error: 自定义模板类作为容器模板参数
//未完成
using namespace std;
template<typename T1,typename T2> class Data{
	public:
		Data()=default;
		Data(const T1&,const T2&);
		Data(const Data&);
		~Data()=default;
		T1 t1;
		T2 t2;
};

template<typename T1, typename T2> Data<T1,T2>::Data(const T1& a1, const T2& a2)
:t1(a1)
,t2(a2)
{
	cout<<"template<typename T1, typename T2> Data<T1,T2>::Data(const T1& a1, const T2& a2)"<<endl;
}

int main(){
	
	Data<int,int> data(1,2);
	Data<int,string> data1(1,string("hello"));
	data.t1=1;
	data.t2=10;
	cout<<"t1:"<<data.t1<<endl;
//error	vector<Data<int,string>,std::allocator<Data<int,int>>> v;
//error:	vector<Data<int,int>,std::allocator<Data<int,int>>> v;

//	v.push_back(Data<int,string>(1,string("hell0")));

	return 0;
}
