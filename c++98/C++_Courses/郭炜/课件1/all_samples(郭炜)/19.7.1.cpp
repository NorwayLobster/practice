//program 19.7.1.cpp  不变序列算法示例
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
void Print( int v)
{
	cout << "<" << v << ">";
}
bool LessThen4( int n)
{
	return n < 4;
}
int main()  
{
	cout << "1) " << min(3,4) << "," << max(2.5,8.3) << endl; //输出 1) 3,8.3
	int a[9] = { 1,2,3,4,5,3,4,4,4 }; 
	cout << "2) " << * min_element(a,a+9) <<","<< * max_element(a,a+9)<<endl; 
     //输出 2) 1,5
	cout << "3) " << count(a,a+9,4) << endl; //计算4的个数，输出 3) 4
	cout << "4) " << count_if(a,a+9,LessThen4) << endl; 
     //计算小于4的元素个数，输出 4) 4
	list<int> lst(a,a+9);
	int b[2] = {4,3};
	vector<int> v(b,b+2);// v 是 4,3
	list<int>::iterator p;
	p = find_first_of(lst.begin(),lst.end(),b,b+2); // 找 4,3中的任一元素
	cout << "5) " << distance(lst.begin(),p) << endl; //找到了3 输出 5) 2
	reverse(v.begin(),v.end()); //算法reverse能前后颠倒区间，v变成 3,4
	int * ptr = find_end(a,a+9,v.begin(),v.end());
     //找序列 "3 4"在数组a中最后出现的位置
	cout << "6) " << distance(a,ptr) << endl; //输出 6) 5 
	p = adjacent_find(lst.begin(),lst.end()); //找lst中连续两个相同的元素
	cout << "7) " << * p << "," << distance(lst.begin(),p) << endl; //输出 7) 4,6
	p = search(lst.begin(),lst.end(),v.begin(),v.end());//找序列 "3 4"
	cout << "8) " << distance(lst.begin(),p) << endl;   //输出 8) 2
	ptr = search_n(a,a+9,2,4); //找连续2个4出现的位置
	cout << "9) " << distance(a,ptr) << endl; //输出 9) 6
	cout << boolalpha ;// 以后true,false以字符串形式输出
	cout << "10) " << equal(v.begin(),v.end(),a+2) << endl; 
     //比较v和a+2开始的2个元素，都相等, 输出 10) true
	int c[6] = { 1,2,3,9,7,8 };
	pair<int *, int * > result;
	result = mismatch(c,c+6,a);
	cout << "11) " << * result.first  << "," << * result.second << endl;//输出 11) 9,4
	cout << "12) " << lexicographical_compare(a,a+9,c,c+6) << endl; //输出 12) true
     for_each(a,a+3,Print); //以[a,a+3)中的每个元素为参数，调用Print, 输出 <1><2><3>
	return 0;
}

