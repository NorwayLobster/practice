//program 9.1.1.cpp //八重循环解八皇后问题
#include <iostream> 
#include <cmath>
using namespace std;
bool Valid(int row,int pos[]) //第row行皇后的摆法，是否和前面的冲突
{
	for( int i = 0; i < row; ++ i)
			if( pos[row] == pos[i] || abs(row-i) == abs(pos[row]-pos[i]))
				return false; //冲突
	return true; //不冲突
}
int main()
{
	int pos[8]; // 8 个皇后摆放的位置,行列都从0开始算
	for(pos[0] = 0;pos[0] < 8; ++ pos[0]) 
		for(pos[1] = 0;pos[1] < 8; ++ pos[1]) {
			if( !Valid(1,pos)) //若当前摆法已经和前面的皇后冲突，就试下一摆法
				continue;
			for(pos[2] = 0;pos[2] < 8; ++ pos[2]) {
				if( !Valid(2,pos))
					continue;
				for(pos[3] = 0;pos[3] < 8; ++ pos[3]) {
					if( !Valid(3,pos))
						continue;
					for(pos[4] = 0;pos[4] < 8; ++ pos[4]) {
						if( !Valid(4,pos))
							continue;
						for(pos[5] = 0;pos[5] < 8; ++ pos[5]) {
							if( !Valid(5,pos))
								continue;
							for(pos[6] = 0;pos[6] < 8; ++ pos[6]) {
								if( !Valid(6,pos))
									continue;
								for(pos[7] = 0;pos[7] < 8; ++ pos[7]) {
									if( Valid(7,pos)) {
										for(int k = 0;k < 8; ++k)
											cout << pos[k] << " " ;
										cout << endl;
									}
								}
							}
						}
					}
				}
			}
		}
	return 0;
}

