//program 14.7.1.cpp 共有派生的赋值兼容规则
class A
{
};
class B:public A //公有派生
{
};
int main()
{
   A a;
   B b;
   a = b; //派生类对象赋值给基类对象 
   A & r = b; //派生类对象初始化基类引用 
   A * pa = & b; //派生类对象地址赋值给基类指针 
   B * pb = & b; 
   pa = pb; //派生类指针赋值给基类指针 
   return 0;
}
