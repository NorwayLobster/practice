//program 20.5.5.cpp 单独使用名字空间中的名字
#include <iostream>
#include <vector>
using std::cout;
using std::vector;
using std::endl;
int main()
{
   vector<int> v; //前面交待过，vector是属于std的
   vector<int>::iterator i = v.begin();
   cout << "Hello" << endl; //前面交待过，cout和endl是属于std的
   cout << "World" << endl;
   return 0;
}
