//#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// To execute C++, please define "int main()"

// The TestCase is shown below
// Input : 1 2
// Output : 3
class LRU{
public:
	LRU()
	:_size(0)
	,_capacity(0){	
	}
	~LRU(){	
	}
	int get(int key){
		if(lru_hash.end()!=lru_hash.find(key)){
			update(key);
			return lru_hash[key]->second;
		}
		return -1;
	}
	void set(int key, int val){
		if(lru_hash.end()!=lru_hash.find(key)){
			update(key,val);
		}else{
			if(_size+1>_capacity){
				expire();
			}
			lru_list.push_front(make_pair(key,val));
			lru_hash[key]=lru_list.begin();
			_size++;
		}
	}
private:
	void expire(){
		//
		auto p=lru_list.back();
		lru_list.pop_back();
		//
		lru_hash.erase(p.first);//erase a key,val by key in hash
		_capacity--;
	}
	void update(int key,int val){
		auto iter=lru_hash[key];
		auto p=pair<int,int>(key,val);
		
		lru_list.erase(iter);
		lru_list.push_front(p);
		lru_hash[key]=lru_list.begin();
	}
	void update(int key){
		auto iter=lru_hash[key];
		auto p=*iter;
		
		lru_list.erase(iter);
		lru_list.push_front(p);
		lru_hash[key]=lru_list.begin();
	}
private:
	int _size;
	int _capacity;
	unordered_map<int,list<pair<int,int>>::iterator> lru_hash; //key,iter
	list<pair<int,int>> lru_list; //key,val
};
int main() {
	string words = "Hello, World!";
	cout << words << endl;
	int a, b;
	while(cin>> a >> b)
	cout << "Your result is : "<< a + b << endl;
  	return 0;
}