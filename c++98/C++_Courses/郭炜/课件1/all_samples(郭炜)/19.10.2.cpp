//program 19.10.2.cpp  next_permutation 解n皇后问题
#include <iostream> 
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
bool Valid(int rows,const vector<int> & pos) //前rows行皇后是否冲突
{
	for( int i = 0; i < rows; ++ i)
		for( int j = 0; j < i; ++ j ) 
			if( pos[i] == pos[j] || abs(i-j) == abs(pos[i]-pos[j]))
				return false;
	return true;
}
int main()
{
	int n; 
	cin >> n; //n个皇后
	vector<int> pos(n);  // n个皇后摆放的位置,行列都从0开始算
	for( int i = 0;i < n; ++ i)
		pos[i] = i;
	while( next_permutation(pos.begin(),pos.end())) {
		if(Valid(n,pos)) {
			for( int k = 0; k < n; ++k)
				cout << pos[k] << " ";
			cout << endl;
		}
	}
	return 0;
}
