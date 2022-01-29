#include<iostream>
#include<string>
#include<vector>
#include <functional>
#include<queue>
using namespace std;

// To execute C++, please define "int main()"

// The TestCase is shown below
// Input : 1 2
// Output : 3
string getValidPath(const string& path){
	int len=path.size();
	stack<string> s;
	//step1:
	for(int i=1;i<len;){
		int left=i;
		while(i<len && '/'!=path[i]){
			i++;
		}
		if(i>=len){
			break;
		}
		int next=i+1;
		int len1=i-left;
		string dirName=s.substr(left,len1);
		if("."==dirName || ""==dirName){
		}else if(".."==dirName){
			if(!s.empty()){
				s.pop();
			}
		}else{
			s.push(dirName);
		}
		i=next;
	}
	//step2:
	string res=;
	while(!s.empty()){
		string tmp=s.top();
		res=tmp+"/"+res;
	}
	//note: / is root
	return res;
}
int main() {
	string words = "Hello, World!";
	cout << words << endl;
	int a, b;
	while(cin>> a >> b)
	cout << "Your result is : "<< a + b << endl;
  	return 0;
}