#include <iostream>
#include <list>
#include <vector>


using namespace std;
//using vector
int main(int argc, char const *argv[])
{
	vector<int> monkeys;
	int n, m;
	while(true)
	{
		cin>>n>>m;

		monkeys.clear();

		if(n == 0 && m == 0)
			break;

		for (int i = 1; i <= n; ++i)
		{
			monkeys.push_back(i);
		}
		for(std::vector<int>:: iterator i = monkeys.begin(); i<monkeys.end();++i)
		{
			cout<<*i<<" ";
		}
		cout<<endl;

		std::vector<int>:: iterator it = monkeys.begin();
		while(monkeys.size()>1)
		{
			for (int i = 0; i < m; ++i)
			{
				++it;
				if(it== monkeys.end())
					it= monkeys.begin();
			}
			it= monkeys.erase(it);
			if(it==monkeys.end())
				it=monkeys.begin();

		}

		cout<<"The king is:"<<monkeys.front()<<endl;

	}//while 
	return 0;
}












//using list
/*
int main(int argc, char const *argv[])
{
	list<int> monkeys;
	int n,m;
	while(true)
	{
		cin>>n>>m;
		if(n== 0 && m== 0)
			break;
		monkeys.clear();
		for (int i = 0; i <=n; ++i)
		{
			monkeys.push_back(i);
		}
		list<int>::iterator it = monkeys.begin();
		while(monkeys.size()>1)
		{
			for (int i = 0; i < m; ++i)
			{
				++it;
				if( it== monkeys.end())
					it=monkeys.begin();
			}
			it = monkeys.erase(it);
			if(it==monkeys.end())
				it = monkeys.begin();

		}
		cout<<"the king:"<<monkeys.front()<<endl;

	}
	return 0;
}*/