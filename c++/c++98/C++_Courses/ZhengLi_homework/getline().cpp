#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{	string str[2];

	cin.getline(str,",");
	cin.getline(str);

	cout<<str[0]<<endl;
	cout<<str[1]<<endl;

	return 0;
}