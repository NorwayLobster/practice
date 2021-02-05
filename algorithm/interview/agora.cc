/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2021-01-31 15:24:48
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-31 15:34:58
 * @FilePath: /practice/algorithm/interview/agora.cc
 */
#include <iostream>
#include <numeric>
using namespace std;

unsigned long long int mygcd(unsigned long long int x, unsigned long long int y) {
	// int factor = 0;   //计数器
	// int temp;
  unsigned long long int factor = 0;   //计数器
  unsigned long long int temp;
	//大数赋给x，小数赋给y
	if (x < y) {
		temp = x;
		x = y;
		y = temp;
	}
	if (0 == y) {
		return 0;
	}
	while (x != y) {
		if (x & 0x1) {
			if (y & 0x1) {   //x,y都为奇数
				y = (x - y) >> 1;
				x -= y;
			}
			else {    // x为奇数，y为偶数
				y >>= 1;
			}
		}
		else {
			if (y & 0x1) {   // x为偶数，y为奇数
				x >>= 1;
				if (x < y) {
					temp = x;
					x = y;
					y = temp;
				}
			}
			else {   //x,y均为偶数
				x >>= 1;
				y >>= 1;
				++factor;
			}
		}
	}
	return (x << factor);
}

int main(){

    unsigned long long int a;
    cin >> a;
    unsigned long long int res=0;
    unsigned long long int n=0;
    while(1){
        res=res*10+1;
        n++;
        // if(mygcd(res,a)==a){
        if(std::gcd(res,a)==a){
            cout<<n<<endl;
            return 0;
        }
    }
    return 0;
}
