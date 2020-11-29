//program 3.2.2.cpp   È±ÉÙbreakµÄcase
#include <iostream>
using namespace std;
int main()
{
 	int n;
 	cin >> n;
 	switch(n%6) {
		case 0:
			 cout << "case 0" << endl;
			 break;		
		case 1:
			 cout << "case 1" << endl;
		case 2:
		case 3:
			 cout << "case 2 or 3" << endl;
			 break;
		case 4:
			 cout << "case 4" << endl;
			 break;
		default:
			 cout << "default";	
  	}
  	return 0;
}
