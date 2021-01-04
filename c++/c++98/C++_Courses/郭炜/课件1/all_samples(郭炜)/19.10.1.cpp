//program 19.10.1.cpp 变序算法示例
#include <iostream>
#include <algorithm>
#include <ctime>
#include <iterator>
using namespace std;
bool LessThan4(int n) { return n < 4; }
int main()
{
	ostream_iterator<int> oit(cout,",");
	int a[5] = { 1,2,3,4,5};
	reverse(a,a+5); //a成为 5 4 3 2 1
	cout << "1) "; copy(a,a+5,oit); cout << endl; //输出 1) 5,4,3,2,1,
	int b[5] = {0,0,0,0,0};
	reverse_copy(a,a+5,b); 
	cout << "2) "; copy(b,b+5,oit); cout << endl; //输出 2) 1,2,3,4,5,
	cout << "3) "; copy(a,a+5,oit); cout << endl; //输出 3) 5,4,3,2,1,
	bool result = prev_permutation(a,a+5); 
	cout << "4) "; copy(a,a+5,oit); cout << endl; //输出 4) 5,4,3,1,2,
	result = next_permutation(a,a+5);
	cout << "5) "; copy(a,a+5,oit); cout << endl; //输出 5) 5,4,3,2,1,
	result = next_permutation(a,a+5);
	cout << "6) " << result << endl;  //"54321" 是最大排列，没下一个排列了, 输出 6) 0,
	srand(time(0));//设置随机种子
	random_shuffle(a,a+5);
	cout << "7) "; copy(a,a+5,oit); cout << endl;  //输出 7) 5,2,4,1,3,
	partition(a,a+5,LessThan4);	//把小于4的元素都排前面
	cout << "8) "; copy(a,a+5,oit); cout << endl;  //输出 8) 3,2,1,4,5,
	random_shuffle(a,a+5);
	cout << "9) "; copy(a,a+5,oit); cout << endl;  //输出 9) 1,3,5,2,4,
	stable_partition(a,a+5,LessThan4); //把小于4 的元素都排前面，还要保序
	cout << "10) "; copy(a,a+5,oit); cout << endl; //输出 10) 1,3,2,5,4,
	return 0;
}

