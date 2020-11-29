#include<iostream>
#include <stdlib.h>
using namespace std;

// int main(){
// 	int count=101;
// 	int a;
// 	double b=18;
// 	char flag ;
// 	cout<<"plase just guess the number(1~100),then input it."<<endl;
// 	// cin>>a;

// 	while(cin>>a)
// 	{
// 		// b=0+(int)100*rand()/(RAND_MAX+1);
// 		if (a==b)
// 		{
// 			cout<<"correct!"<<endl;
// 			break;
// 		}
// 		else if(a>b)
// 		cout<<"sorry, your number is bigger than that one";
// 				else  cout<<"sorry, your number is smaller than that one";

// 		cout<<", and plase try again."<<endl;
// 	}//while 
// }









int main(){

	int a;
	double b=18;

	cout<<"plase just guess the number(1~100),then input it:";
	cin>>a;

	do{
		// b=0+(int)100*rand()/(RAND_MAX+1);
		if (a==b)
		{
			cout<<"correct!"<<endl;
			break;
		}
		else if(a>b)
		cout<<"sorry, your number is bigger than that one";
				else  cout<<"sorry, your number is smaller than that one";

		cout<<", and plase try again:";
	}while(cin>>a);
}