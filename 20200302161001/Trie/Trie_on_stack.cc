 ///
 /// @file    Trie.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-03 14:28:10
 ///
 ///complete   Tue Mar  3 17:02:57 CST 2020
//2h 
#include <bits/stdc++.h>
using namespace std;
#define Size 26
#define MaxNodeNum 20
class TrieNodeInfo{
	public:
		TrieNodeInfo();
		~TrieNodeInfo();
		int _passHereNum;
		int _endNum;
};
TrieNodeInfo::TrieNodeInfo(){
	cout<<"TrieNodeInfo()"<<endl;	
}
TrieNodeInfo::~TrieNodeInfo(){
	cout<<"~TrieNodeInfo()"<<endl;	
}

class Trie{
	public:
		Trie();
		~Trie();
		void insertWord(const string&);
		void deleteWord(const string&);
		bool isElement(const string&);
		int prefixNumber(const string &);
	private:
		int _ch[MaxNodeNum][Size];
		int _nodeTotalNum;//已有
		TrieNodeInfo _info[MaxNodeNum];
};

Trie::Trie()
:_nodeTotalNum(1)
//fatal error:_nodeTotalNum(0) //fuck, 1h time for debug
{
	memset(_ch,0,sizeof(int)*MaxNodeNum*Size);
	memset(_info,0,sizeof(TrieNodeInfo)*MaxNodeNum);
	cout<<"Trie()"<<endl;	
}
Trie::~Trie(){
	cout<<"~Trie()"<<endl;
}

void Trie::insertWord(const string & s){
	if(0==s.size()) return ;
	int len=s.size();
	int idx;
	int nodeNum=0;
	for(int i=0;i<len;++i){
		idx=s[i]-'a';//字母信息蕴含在寻址过程中,指针的指向
		if(0==_ch[nodeNum][idx]){//add new node
			_ch[nodeNum][idx]=_nodeTotalNum++;//新节点为_nodeTotalNum, 且节点总数+1
//			cout<<"_ch[nodeNum][idx]:"<<_ch[nodeNum][idx]<<endl;
		}
		_info[nodeNum]._passHereNum++;
		if(len-1==i)
			_info[nodeNum]._endNum++;
//		cout<<"_info[nodeNum]:"<<_info[nodeNum]._endNum<<endl;
		nodeNum=_ch[nodeNum][idx];
	}
}

void Trie::deleteWord(const string &s){
	if(0==s.size()) return ;
	if(!isElement(s)) return ;
	int len=s.size();
	int idx;
	int nodeNum=0;
	for(int i=0;i<len;++i){
		idx=s[i]-'a';//字母信息蕴含在寻址过程中,指针的指向
		_info[nodeNum]._passHereNum--;
		if(len-1==i)
			_info[nodeNum]._endNum--;
		nodeNum=_ch[nodeNum][idx];
	}
	//是否检测passHereNum==0是否释放nodeNum序号空间?
}
int Trie::prefixNumber(const string &s){
	if(0==s.size()) return 0;
	int len=s.size();
	int idx;
	int nodeNum=0;
	for(int i=0;i<len;++i){
		idx=s[i]-'a';//字母信息蕴含在寻址过程中,指针的指向
		if(0==_ch[nodeNum][idx]|| _info[nodeNum]._passHereNum<=0){//add new node
			return 0;
		}
		if(len-1==i)
			return _info[nodeNum]._passHereNum;
		nodeNum=_ch[nodeNum][idx];
	}
	return 0;
}
bool Trie::isElement(const string&s){
	if(0==s.size()) return false ;
	int len=s.size();
	int idx;
	int nodeNum=0;
	for(int i=0;i<len;++i){
		idx=s[i]-'a';//字母信息蕴含在寻址过程中,指针的指向
		if(0==_ch[nodeNum][idx]|| _info[nodeNum]._passHereNum<=0){//add new node
			return false;
		}
		if(len-1==i && _info[nodeNum]._endNum>0)
			return true;
		nodeNum=_ch[nodeNum][idx];
	}
	return false;
}
int main(){
	Trie t;			
	t.insertWord("word");
	cout<<"word bool:"<<t.isElement("word")<<endl;
	cout<<"worde bool:"<<t.isElement("worde")<<endl;
	cout<<"wor bool:"<<t.isElement("wor")<<endl;
	cout<<"door bool:"<<t.isElement("door")<<endl;
	cout<<"word prefixNumber:"<<t.prefixNumber("word")<<endl;
	cout<<"wor prefixNumber:"<<t.prefixNumber("wor")<<endl;
	t.deleteWord("word");
	t.deleteWord("wo");
	cout<<"after delete"<<endl;
	cout<<"word bool:"<<t.isElement("word")<<endl;
	cout<<"word prefixNumber:"<<t.prefixNumber("wor")<<endl;
	t.deleteWord("word");
	cout<<endl;

	t.insertWord("wor");
	cout<<"wor bool:"<<t.isElement("wor")<<endl;
	cout<<"wor prefixNumber:"<<t.prefixNumber("wor")<<endl;
	t.deleteWord("wor");
	cout<<"wor bool:"<<t.isElement("wor")<<endl;
	cout<<"wor prefixNumber:"<<t.prefixNumber("wor")<<endl;
	return 0;
}
