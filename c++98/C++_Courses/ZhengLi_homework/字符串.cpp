#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	
	char * p ="plase input your name:\n";
	cout<<p;
	char a[20];
	char * pname = a;
	// char * pname=p;//the type of p is const char * 
	cin>>*pname;
	cout<<"your name is "<<pname<<endl;
	cout<<endl;



	cin>>pname;

	// cin>>a;
	cout<<"your name is "<<pname<<endl;

	return 0;
}











// int main(int argc, char const *argv[])
// {
	
// 	char * p ="plase input your name:\n";
// 	cout<<p;
// 	char a[20];
// 	char * pname = a;
// 	// cin>>*pname;
// 	// cout<<"your name is "<<pname<<endl;
// 	// cout<<endl;



// 	cin>>pname;

// 	// cin>>a;
// 	cout<<"your name is "<<*pname<<endl;
// 	cout<<"your name is "<<*(&pname)<<endl;

	
// 	return 0;
// }








