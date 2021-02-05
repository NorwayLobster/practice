/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2021-02-05 14:19:55
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-02-05 13:16:43
 * @FilePath: /practice/algorithm/interview/huawei-买股票且不限买卖次数-机试.cc
 */
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
int main(){
    string input;
    getline(cin,input);
    string word;
    stringstream ss;
    ss<<input;
    long long int a;
    vector<long long int> res;
    while(ss>>word){
      int len=word.size();
      if(word[len-1]=='Y'){
        word.pop_back();
        a=stoll(word);
      }else{
        word.pop_back();
        a=stoll(word);
        a=a*7;
      }
      cout<<a<<",";
      res.push_back(a);
    }
    cout<<endl;
    int len=res.size();
    int sum=0;
    for(int i=1;i<len;++i){
      int diff=res[i]-res[i-1];
      if(diff>0){
        sum+=diff;
      }
    }
    cout<<sum<<endl;
    return 0;
}