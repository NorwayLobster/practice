#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;

int main (){
	const int N=5;
	std::vector<int> v(N);
	for (int i = 0; i < N; ++i)
	{
		cin>>v[i];
	}

	transform(v.begin(), v.end(), ostream_iterator<int>(cout," "),negate<int> ());
	cout<<endl;
	return 0;
}//main