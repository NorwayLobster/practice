#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{	
	int n;
	cin>>n;
	cout<<endl;
	std::vector<int> v(n, 0);

	for (int i = 0; i < n; ++i)
	{
		cout<<v[i]<<endl;

	}
	cout<<endl;

	int x;
	// cin>>x;


	std::vector<int> s(2);
	// v.push_front(x)
	// cout<<"push_front"
	// 	for (int i = 0; i < n; ++i)
	// {
	// 	cout<<v[i]<<endl;

	// }

		for (int i = 0; i < s.size(); ++i)
	{
		cout<<s[i]<<endl;

	}

	cout<<"push_back:size():"<<s.size()<<endl;
	for (int i = 0; i < 2; ++i)
	{	cin>>x;
		s.push_back(x);
	}

	cout<<endl;
	cout<<"size():"<<s.size()<<endl;


		for (int i = 0; i < s.size(); ++i)
	{
		cout<<s[i]<<endl;

	}
	cout<<endl;
	s.assign(s.size(),8);
	for (int i = 0; i < s.size(); ++i)
	{
		cout<<s[i]<<endl;

	}

	cout<<endl;
	s.assign(n,9);
	for (int i = 0; i < s.size(); ++i)
	{
		cout<<s[i]<<endl;

	}

	cout<<endl;

	std::vector<int> :: iterator j;

	j=s.insert(s.begin(),10);

	for (int i = 0; i < s.size(); ++i)
	{
		cout<<s[i]<<endl;

	}


	cout<<endl;
	
	// std::vector<int> :: iterator i;

	s.insert(j+2,3,110);

	for (int i = 0; i < s.size(); ++i)
	{
		cout<<s[i]<<endl;

	}


	cout<<endl;

	std::vector<int>::iterator m =s.erase(s.end()-1);
	cout<<"m:"<<*m;
	cout<<endl;



	for (int i = 0; i < s.size(); ++i)
	{
		cout<<s[i]<<endl;

	}
	cout<<endl;

	cout<<s.front()<<endl;
	cout<<s.back()<<endl;

	cout<<endl;
	s.resize(3);
	for (int i = 0; i < s.size(); ++i)
	{
		cout<<s[i]<<endl;

	}

	cout<<endl;

	int t1,t2;
	cin>>t1>>t2;
	s.push_back(t1);
	s.push_back(t2);
	cout<<endl;

	for (int i = 0; i < s.size(); ++i)
	{
		cout<<s[i]<<endl;

	}
	cout<<endl;

	cout<<s.back()<<endl;
	cout<<endl;
	s.pop_back();
	cout<<s.back()<<endl;

	return 0;
}