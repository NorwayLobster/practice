/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2021-01-30 20:35:45
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-31 02:07:28
 * @FilePath: /practice/algorithm/interview/utf-8&文件逆序输出-百度二面.cc
 */
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
int main(){
  fstream f("./a.txt");
  // fseek(line);//line: 
  //\n
  //line:  

  // wstring line1="您好";
  // cout<<line1<<endl;
  // for(auto iter1=line1.rbegin();iter1!=line1.rend();++iter1){
  //   cout<<*iter1;
  // }
  // cout<<endl;
  // cout<<endl;

  string line="您好";
  vector<string> txt;


  // u16string line="您好";
  // vector<u16string> txt;

  // wstring line;
  // vector<wstring> txt;
  while(getline(f,line)){
    //reverse(line.begin(), line.end());
    txt.push_back(line);
    line.clear();
  }
  for(auto iter=txt.rbegin();iter!=txt.rend();++iter){
    for(auto iter1=iter->rbegin();iter1!=iter->rend();++iter1){
      cout<<*iter1;
    }
    cout<<endl;
  }
  // 1 byte, 2 byte 
  // 111000, 
  vector<vector<string>> res;
  reverse(txt.begin(), txt.end());

  // for(auto& line: txt){//ranged-for 
  for(int i=0;i<(int)txt.sizez();i++){
    string& line=txt[i];
    vector<string> v;//字符容器
    for(int i=0;i<(int)line.size();){
      auto ch=line[i];
      int num;
      if(ch&&0x01){// 
        if(){
        //num=3 byte
          v.push_back(line.substr(i,3));
        }else{//num=2 byte
          v.push_back(line.substr(i,2));
        }else{//num=1 byte
          v.push_back(line.substr(i,1));
        }
      }
      i+=num;
    }
    res.push_back(v);
    v.clear();
    cout<<line<<endl;
  }

  for(auto& v: txt){
    reverse(v.begin(),v.end());
    for(auto& s:v){
      cout<<s;
    }
    cout<<endl;
  }
  return 0;
}