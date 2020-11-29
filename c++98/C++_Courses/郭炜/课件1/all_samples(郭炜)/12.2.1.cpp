//program 12.2.1.cpp  析构函数
#include <iostream>
using namespace std;
class CDemo {
    public:
	~CDemo()  //析构函数
    {  
        cout<< "Destructor called" << endl; 
    } 
};
int main () {
	CDemo array[2];        //构造函数调用2次
	CDemo  * pTest = new CDemo;  //构造函数调用
	delete pTest;          //析构函数调用
	cout << "-----------------------" << endl;
     pTest = new CDemo[2]; //构造函数调用2次
	delete [] pTest;      //析构函数调用2次 
	cout << "Main ends." << endl;    
	return 0;
}

