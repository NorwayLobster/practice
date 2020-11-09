 ///
 /// @file    main.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-29 06:35:34
 ///
 
#include <bits/stdc++.h>
using namespace std;
char firstOnlyOnceCharacter(char * str){
	if(NULL==str) return '\0';
	int hashTable[256]={0};
	char * p=str;
	while('\0'!=*p){
		++hashTable[*p-1];
		++p;
	}
	p=str;
	while('\0'!=*p){
		if(1==hashTable[*p-1])
			break;
		++p;
	}
	return *p;
}
class firstOnlyOnceCharacterStream{
public:
	firstOnlyOnceCharacterStream()
		:_index(0)
		 ,_hashTable(256,-1)
		{}
	void insert(char ch);	
	char firstOnlyOnceCharacter();
private:
	int _index;
	vector<int> _hashTable;
};

void firstOnlyOnceCharacterStream::insert(char ch){
		cout<<"ch:"<<int(ch)-1<<endl;
		if(-1==_hashTable[ch-1])
			_hashTable[ch-1]=_index;
		else if(_hashTable[ch-1]>=0)
			_hashTable[ch-1]=-2;
		++_index;
}

char firstOnlyOnceCharacterStream::firstOnlyOnceCharacter(){
	int min=INT_MAX;//流中最大的字符个数
	int ret=-1;
	for(int i=0;i<256;++i){
		if(_hashTable[i]>=0 && _hashTable[i]<=min){
			min=_hashTable[i];	
			ret=i;
		}
	}
	if(-1==ret)
		return '\0';
	else
		return (char)(ret+1);
}

int main(){
	char a[]="abaccbdedff";
	char ch=firstOnlyOnceCharacter(a);
	cout<<ch<<endl;
	firstOnlyOnceCharacterStream f;
	f.insert('a');
	f.insert('b');
	f.insert('a');
	f.insert('b');
	f.insert('c');
	f.insert('c');
	f.insert('d');
	f.insert('f');
	ch=f.firstOnlyOnceCharacter();
	cout<<ch<<endl;
	return 0;
}
