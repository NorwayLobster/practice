//program 20.4.7.cpp out_of_range异常
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string> 
using namespace std;
int main () 
{
  vector<int> v(10);
  try {
    v.at(100)=100;  //抛出out_of_range异常
  }
  catch (out_of_range& e) {
    cerr << e.what() << endl;
  }
  string s = "hello";
  try {
    char c = s.at(100); //抛出out_of_range异常
  }
  catch (out_of_range& e) {
    cerr << e.what() << endl;
  }
  return 0;
}

