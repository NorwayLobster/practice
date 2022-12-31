 ///
 /// @file    test.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-27 01:07:57
 ///
 
#include <iostream>
using std::cout;
using std::endl;
int main(int argc, char**argv)
{
    cout<<"argc="<<argc<<endl;
    cout<<"argv:";
    for( int i=0;i<argc;i++){
       cout <<argv[i]<<",";
    }
    cout<<endl;
	return 0;
}
