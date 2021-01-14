#include <iostream>

#include <string>
 using namespace std;

 int main(int argc, char const *argv[])
 {
 	
 	string line,line1;
 	cout<<"Type a line terminated by '.'"<<endl;
 	getline(cin, line ,'.');
 	getline(cin, line1);

 	cout<<line <<endl;
 	cout<<line1<<endl;


 	return 0;
 }