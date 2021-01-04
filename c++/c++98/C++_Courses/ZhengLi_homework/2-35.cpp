#include <iostream>
# include <iomanip>

using namespace std;

// int main(int argc, char const *argv[])
// {
// 	for (int i = 1; i < 10; ++i)
// 	{
// 		for (int j = i; j < 10; ++j)
// 		{
// 			cout<<i<<"*"<<j<<'='<<i*j<<endl;

// 		}
// 		cout<<endl;
// 	}
// 	return 0;
// }



int main(int argc, char const *argv[])
{
	cout<<' ';
	for (int i = 1; i < 10; ++i)
	{
		cout<<setw(4)<<i;
	}
	cout<<endl;
	for (int i = 1; i < 10; ++i)
	{	cout<<i;
		for (int j = i; j < 10; ++j)
		{
		
			cout<<setw(4)<<i*j;		}
			cout<<endl;
	}
	return 0;
}