//program 20.5.4.cpp 单独使用名字空间中的名字
#include <iostream>
#include <vector>
int main()
{
   std::vector<int> v;
   std::vector<int>::iterator i = v.begin();
   std::cout << "Hello" << std::endl;
   std::cout << "World" << std::endl;
   return 0;
}

