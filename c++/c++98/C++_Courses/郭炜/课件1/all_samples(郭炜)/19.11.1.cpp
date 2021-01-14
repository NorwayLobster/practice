//program 19.11.1.cpp 排序算法示例
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int main()  
{
	ostream_iterator<int> oit(cout,",");
	int a[5] = { 4, 5, 3, 1, 2 };
	int b[5];
	memcpy(b,a,sizeof(a));//复制a到b
	partial_sort(b,b+3,b+5);//使前3个元素就位 
	cout << "1) "; copy(b,b+5,oit); cout << endl; //输出 1) 1,2,3,5,4,
	memset(b,0,sizeof(b)); //b变成全0 
	partial_sort_copy(a,a + 4,b,b+3);//把[a,a+4)排序结果的前3个拷贝到b 
	cout << "2) "; copy(a,a+5,oit); cout << endl; //a不变 输出 2) 4,5,3,1,2, 
	cout << "3) "; copy(b,b+5,oit); cout << endl; //输出 3) 1,3,4,0,0,
	int c[8] = { 4,1,2,6,5,3,7,0};
	nth_element(c,c+3,c+8);
	cout << "4) "; copy(c,c+8,oit); cout << endl; //输出 4) 0,1,2,3,5,6,7,4, 
	memcpy(b,a,sizeof(a));
	make_heap(b,b+5); //把b变成一个堆
	cout << "5) "; copy(b,b+5,oit); cout << endl;//输出 5) 5,4,3,1,2, 
	vector<int> v(b,b+5); //因为b是个堆，所以v也是个堆
	v.push_back(9); //往堆v中添加一个元素后，v就可能不是堆了 
	push_heap(v.begin(),v.end()); //将v恢复成堆 
	cout << "6) "; copy(v.begin(),v.end(),oit); cout << endl; //输出 6) 9,4,5,1,2,3
	pop_heap(v.begin(),v.end());  //拿走堆顶的元素 
	cout << "7) "; copy(v.begin(),v.end(),oit); cout << endl; //输出 7) 5,4,3,1,2,9 
	sort_heap(v.begin(),v.end()-1);//排序 
	cout << "8) "; copy(v.begin(),v.end()-1,oit); cout << endl; //输出 8) 1,2,3,4,5, 
	return 0;
}

