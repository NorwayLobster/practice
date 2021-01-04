//program 12.5.1.cpp 常量成员函数
#include <iostream>
using namespace std;
class Sample {
	public:
		   Sample() { }
		void GetValue()  const;
}; 
void Sample::GetValue() const
{
}
int main()
{
 	const Sample o;
  	o.GetValue();	//常量对象上可以执行常量成员函数
  	return 0;
}

