// #include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include <functional>
#include<queue>
///排序: aba aba abaaa abaaaa abc  abcd bcd
///1: abaaba abaaa abaaaa abc  abcd bcd ---> abaaa abaaaa abaaba  abc  abcd bcd


/// abaabc abcd bcd
/// abaabc abcd bcd
/// abaabcabcd bcd

//abcba
//abdaa
//way1: aba abc 小
//way2: abc aba
//string: 字典序最小
using namespace std;
string getMinCharOrder(vector<string>& v){
    std::priority_queue<string, std::vector<string>, std::greater<string> > pq;
    // priority_queue<string, vector<string>, greater<string>> pq;//小根堆
    int len=v.size();
    for(int i=0;i<len;++i){
        pq.push(v[i]);
    }
    
    cout<<"top:"<<pq.top()<<endl;

    while(!pq.empty()){
        string min1=pq.top();
        pq.pop();
        if(pq.empty()){
            return min1;
        }
        string min2=pq.top();
        pq.pop();
        if(min1+min2<min2+min1){//ab+aba<aba+ab
            pq.push(min1+min2);
        }else{
            pq.push(min2+min1);//ab+
        }
    }
    return  "";
}

int main(){
    // vector<string> v{"abc", "abc", "abd"};
    vector<string> v;
    v.push_back("ab");
    v.push_back("aba");
    // v.push_back("bb");
    // v.push_back("aa");
    // v.push_back("abc");
    //  std::vector<std::string> words1 {"the", "frogurt", "is", "also", "cursed"};
    string res=getMinCharOrder(v);
    cout<<"res:"<<res<<endl;
    return 0;
}