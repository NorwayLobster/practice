#include <iostream>

#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	std::vector<std::vector<int> > v;

	// double x;

	for (int i = 0; i < 5; ++i)
	{
		cout<<v[i].capacity()<<endl;
		
		v[i].reserve(9);
		for (int j = 0; j < 9; ++j)
		{	
			// cin>>x;
			v[i].push_back(j+i);
		// cout<<v[i].capacity()<<endl;

		}
		cout<<v[i].capacity()<<endl;
		// cout<<v[i].size()<<endl;
		cout<<endl;


	}

		v.reserve(5);
		cout<<v.capacity()<<endl;
		cout<<v.size()<<endl;
	

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<v.back().front()<<endl;


	return 0;
}