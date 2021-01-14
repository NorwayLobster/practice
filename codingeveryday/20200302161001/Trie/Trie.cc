 ///
 /// @file    Trie.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-03-03 14:28:10
 ///
 ///complete   Tue Mar  3 17:02:57 CST 2020
//2.5h 
#include <bits/stdc++.h>
using namespace std;
#define SIZE 26
class TrieNode{
	public:
		TrieNode();
		~TrieNode();
		int passHereNum;
		int endNum;
		TrieNode * next[SIZE];
};
TrieNode::TrieNode(){
	cout<<"TrieNode()"<<endl;	
}
TrieNode::~TrieNode(){
	cout<<"~TrieNode()"<<endl;	
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
		TrieNode * root;
};
Trie::Trie()
:root(new TrieNode())
{
	cout<<"Trie()"<<endl;	
}
void destrucotr(TrieNode*head);
Trie::~Trie(){
	cout<<"~Trie()"<<endl;

	//构造或析构函数中想提前退出，可以用return
	if(NULL==root){ return ;}//root若Trie对象构造，不可能为空
	destrucotr(root);
	delete root;
	root=NULL;
}
void destrucotr(TrieNode*head){
	for(int i=0;i<SIZE;++i){
		if(NULL!=head->next[i]){
			destrucotr(head->next[i]);
			delete head->next[i];
			head->next[i]=NULL;
		}
	}
	return ;
}

void Trie::insertWord(const string & s){
	if(0==s.size()) return ;
	TrieNode*head=root;
	int c;
	int len=s.size();
	for(int i=0;i<len;++i){
		c=s[i]-'a';//字母信息蕴含在寻址过程中,指针的指向
		if(NULL==head->next[c]){
			head->next[c]=new TrieNode();
		}
		head->next[c]->passHereNum++;
		if(len-1==i)
			head->next[c]->endNum++;
		head=head->next[c];
	}
}
void Trie::deleteWord(const string &s){
	if(0==s.size()) return ;
	if(!isElement(s)) return ;
	TrieNode*head=root;
	int c;
	int len=s.size();
	for(int i=0;i<s.size();++i){
		c=s[i]-'a';
		head->next[c]->passHereNum--;
		if(len-1==i)
			head->next[c]->endNum--;
		head=head->next[c];
	}
	//是否检测passHereNum==0是否释放空间?
}
int Trie::prefixNumber(const string &s){
	if(0==s.size()) return 0;
	TrieNode*head=root;
	int c;
	int len=s.size();
	for(int i=0;i<len;++i){
		c=s[i]-'a';//
		if(NULL==head->next[c]||head->next[c]->passHereNum<=0){
			return 0;
		}
		if(len-1==i)
			return head->next[c]->passHereNum;
		head=head->next[c];
	}
	return 0;
}
bool Trie::isElement(const string&s){
	if(0==s.size()) return false ;
	TrieNode*head=root;
	int c;
	int len=s.size();
	for(int i=0;i<len;++i){
		c=s[i]-'a';
		if(NULL==head->next[c]||head->next[c]->passHereNum<=0){
			return false;
		}
		if(len-1==i&&head->next[c]->endNum>0)
			return true;
		head=head->next[c];
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
