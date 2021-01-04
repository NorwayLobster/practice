#include <iostream>
using namespace std;

int main(){
    cout<<"The char of ASCII CODE between 32 and 127 are blow:"<<endl;
    char a;
    int b=32;

    for(;b<=127; ++b){
  		a=(char)b;

    	cout<<a<<"\n";

    }

    cout<<"end"<<endl;

    return 0;
}
