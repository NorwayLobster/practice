#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	std::vector<double> v;
	int n,m;
	cin>>n;
	cin>>m;

	double x;
	for (int i = 0; i < n; ++i)
	{
		cin>>x;
		v.push_back(x);
	}

	sort(v.begin(), v.begin()+m);
	// for (int i = 0; i < n; ++i)
	// 	cout<<v[i]<<' ';
	// cout<<endl;


	sort(v.begin()+m, v.end(), greater<double>());
	for (int i = 0; i < n; ++i)
	{
		cout<<v[i]<<' ';

	}
	cout<<endl;
	return 0;
}