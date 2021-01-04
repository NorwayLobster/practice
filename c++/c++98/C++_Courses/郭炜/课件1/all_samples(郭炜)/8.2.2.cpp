//8.2.2.cpp  用联合模拟寄存器
#include <iostream>
using namespace std;
union Register
{
	unsigned int word; // word作为计算机术语是"字"的意思，表示32位
	struct {
		unsigned short L;  //寄存器的低16位
		unsigned short H;  //寄存器的高16位
	}data;
};
int main()
{
	Register AX;
	AX.word = 0x12345678;
	AX.data.H = 0x9999;
	cout << hex << AX.word << "," << AX.data.L << "," << AX.data.H;
}

