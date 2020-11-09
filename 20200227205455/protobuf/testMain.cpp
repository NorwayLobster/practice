 ///
 /// @file    testMain.cpp
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-28 02:11:29
 ///
 
#include <iostream>
#include <string>
#include <vector>
#include "serialization.queryResult.pb.h"
using std::cout;
using std::endl;
using namespace std;
int main(){
	string s1="hello";
	cout<<"s1:"<<s1<<endl;
	int a=1;
	Search::SearchResult search_result;	
	search_result.set_query(s1);
	search_result.set_str(s1);
	search_result.set_id(4);
	search_result.set_opt(3);
	search_result.set_page_number(2);
	search_result.set_result_per_page(1);

//note:可以在.proto文件中设置，option optimize_for = LITE_RUNTIME;     // 使用清凉版，没有反射等高级功能
	string encoded;//信息的中间载体, 在网络中传播, 中间载体可以是string, 数组，


//1.SerializeToFileDescripter()// 序列化到文件，fd接口
//2.ParseFromFileDescripter() // 从文件中解析
//
//1.SerializeToOstream()// 序列化到文件，流接口
//2.ParseFromIstream()
//
//                         encoded
//	search_result----------------------------->search_result_decode
		
//1.SerializeToString()
	bool ret=search_result.SerializeToString(&encoded);
	cout<<"ret:"<<ret<<endl;
	cout<<"encoded:"<<encoded<<endl;

	Search::SearchResult search_result_decode;	
//2.ParseFromString()
	ret=search_result_decode.ParseFromString(encoded);

	cout<<"ret:"<<ret<<endl;
	cout<<"id:"<<search_result_decode.id()<<endl;
	cout<<"opt:"<<search_result_decode.opt()<<endl;
	cout<<"page_number:"<<search_result_decode.page_number()<<endl;
	cout<<"result_per_page:"<<search_result_decode.result_per_page()<<endl;
	cout<<"str:"<<search_result_decode.str()<<endl;
	cout<<"query:"<<search_result_decode.query()<<endl;
	

//3.SerializeToArray()// 序列化到array
	vector<int> v;
	size_t len =search_result.ByteSizeLong();
	cout<<"len:"<<len<<endl;
	v.resize(len);
	ret=search_result.SerializeToArray(v.data(),v.size());
	cout<<"ret:"<<ret<<endl;
	cout<<"encoded:"<<encoded<<endl;

//4.ParseFromArray()
//
//5.SerializeToCodedStream()// 序列化到
//6
//
//7.SerializeToZeroCopyStream()// 序列化到
//8
//
//9 protobuf与json相互转化的接口
//
	return 0;
}

