//program 20.2.1.cpp typeid和type_info用法示例
//(本程序修改自http://www.cplusplus.com/reference/std/typeinfo/type_info/)
#include <iostream>
#include <typeinfo> //要使用typeinfo，需要此头文件
using namespace std;
struct Base { };    //非多态基类
struct Derived : Base { };
struct Poly_Base {virtual void Func(){ } }; //多态基类
struct Poly_Derived: Poly_Base { };
int main() 
{
  //基本类型
  long i;  int * p = NULL;
  cout << "1) int is: " << typeid(int).name() << endl; //输出 1) int is: int
  cout << "2) i is: " << typeid(i).name() << endl; //输出 2) i is: long
  cout << "3) p is: " <<  typeid(p).name() << endl; //输出 3) p is: int *
  cout << "4) *p is: " <<  typeid(*p).name() << endl ; //输出 4) *p is: int
  //非多态类型
  Derived derived;
  Base* pbase = &derived;
  cout << "5) derived is: " << typeid(derived).name() << endl; 
        //输出 5) derived is: struct Derived
  cout << "6) *pbase is: " << typeid(*pbase).name() << endl; 
        //输出 6) *pbase is: struct Base
  cout << "7) " << (typeid(derived)==typeid(*pbase) ) << endl; //输出 7) 0
  // 多态类型
  Poly_Derived polyderived;
  Poly_Base* ppolybase = &polyderived;
  cout << "8) polyderived is: " << typeid(polyderived).name() << endl;
        //输出 8) polyderived is: struct Poly_Derived
  cout << "9) *ppolybase is: " << typeid(*ppolybase).name() << endl;
        //输出 9) *ppolybase is: struct Poly_Derived
  cout << "10) " << (typeid(polyderived)!=typeid(*ppolybase) ) << endl; //输出 10) 0
}

