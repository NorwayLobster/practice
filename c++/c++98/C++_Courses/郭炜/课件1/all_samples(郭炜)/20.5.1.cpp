//program 20.5.1.cpp 名字空间简单用法
namespace graphics
{
	class A	{	}; // A 属于名字空间 graphics
}
int main()
{
	A a;           //编译出错，A没有定义
	graphics::A b; //OK, 指名了A所属的名字空间
	return 0;
}

