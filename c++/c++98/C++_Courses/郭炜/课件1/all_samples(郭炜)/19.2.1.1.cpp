//program 19.2.1.1.cpp  vector基本用法
#include <iostream>
#include <vector> //使用vector需要包含此头文件
using namespace std;
template<class T>
void PrintVector( const vector<T> & v)
{ //用以输出vector容器的全部元素的函数模板
	typename vector<T>::const_iterator i; 
//typename用来说明 vector<T>::const_iterator是个类型 ,在VS 2008中不写也可以 
	for( i  = v.begin(); i != v.end(); ++i)	
		cout << * i << " ";
	cout << endl;
}
int main()  
{	
	int a[5] = { 1,2,3,4,5 };    
	vector<int> v(a,a+5);  //将数组a的内容放入v
cout << "1) " << v.end()  - v.begin() << endl; //两个随机迭代器可以相减，输出 1) 5
	cout << "2) "; PrintVector(v); //输出：2) 1 2 3 4 5
	v.insert( v.begin() + 2, 13 ); //在begin()+2位置插入 13
	cout << "3) "; PrintVector(v); //输出：3) 1 2 13 3 4 5
	v.erase( v.begin() + 2);       //删除位于 begin() + 2的元素 
	cout << "4) "; PrintVector(v); //输出：4) 1 2 3 4 5
	vector<int> v2(4,100);  //v2 有4个元素，都是100
	v2.insert( v2.begin(),v.begin()+ 1,v.begin()+3);//将v的一段插入v2开头
	cout << "5) v2: "; PrintVector(v2); //输出: 5) v2: 2 3 100 100 100 100
	v.erase( v.begin() + 1, v.begin() + 3); //删除 v 上的一个区间,即 2,3 
	cout << "6) "; PrintVector(v); //输出: 6) 1 4 5
	return 0;
}
