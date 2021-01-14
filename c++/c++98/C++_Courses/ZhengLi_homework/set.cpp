#include <iostream>
#include <set>
#include <string>
#include <vector>

#include <algorithm>

using namespace std;


int main(int argc, char const *argv[])
{
	multiset<int> s;
	vector<int> ans;
	int n,x;
	cin>>n;
	string str;

	// pair<bool,int> ans;
	for (int i = 0; i < n; ++i)
	{
		cin>>str>>x;
		if(str=="add") {
			s.insert(x);
			ans.push_back(s.count(x));
			// cout<<s.count(x)<<endl;
		}

		else if(str[0]=='d')	{
			int a=s.count(x);
			pair<multiset<int>::iterator,multiset<int>::iterator> p1;
			p1= s.equal_range(x);
			// p1.first=lower_bound(x);
			// p1.second=upper_bound(x);



			s.erase(p1.first,p1.second);

			// multiset<int>::iterator it;
			// it=lower_bound(x);
			// for (; it ==upper_bound(x); ++it)
			// {
			// 	s.erase(x);
			// }
			ans.push_back(s.count(a));

			// cout<<a<<endl;
		}

		// if(str=="ask")
		else 
		 {
			multiset<int>::iterator it= s.find(x);
			if(it==s.end())
				cout<<0;
			else cout<<1;
			s.insert(x);
			cout<<' '<<s.count(x)<<endl;
		}

	}

	for (int i = 0; i < n; ++i)
	{
		cout<<ans[i]<<endl;
	}
	// cout<<endl;

	return 0;
}