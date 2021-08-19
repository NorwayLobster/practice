#include<bits/stdc++.h>
// 1.
using namespace std;
int num=256;
string mySort(const string& s){
   int len=s.size();
   if(0==len) return "";
   if(1==len) return s;
   //init
//    vector<pair<pair<int, int>,int>> bucket(256);
//    for(int i=0;i<bucket.size();++i){
    //    bucket[i].first.first=0;
//    }
    // pair<pair<int,int>,int> p(pair<int,int>(0,0),0);
   vector<pair<pair<int, int>,int>> bucket(256, pair<pair<int,int>,int>(pair<int,int>(0,0),0)); //fre, firstApperanceIndex
   //step1: collect info
   for(int i=0;i<len;++i){
       int index=s[i]-'0';
       pair<pair<int,int>,int>& p=bucket[index];
       p.second=index;
       if(p.first.first>0){
           p.first.first++;
       }else{
           p.first.first++;
           p.first.second=i;
       }
   }
   //step2:
   sort(bucket.begin(),bucket.end(),[](const pair<pair<int,int>,int>& left, const pair<pair<int,int>,int>& right)->bool{
       if(left.first.first==right.first.first){
            return left.first.second<right.first.second;
        }else{
            return left.first.first>right.first.first;
        }
   });
   //step3:
   len=bucket.size();
   string res;
   for(int i=0;i<len;i++){
       int fre=bucket[i].first.first;
       char ch=bucket[i].second+'0';
       cout<<"fre:"<<fre<<endl;
       for(int j=0;j<fre;++j){
           cout<<"ch:"<<ch<<endl;
            res.push_back(ch);           
       }
   }
   return res;
}
int main(){
    // string s="123123234";
    // string s="123123412345 ";
    string s="";
    // string s="213123412345";
    string res=mySort(s);
    cout<<"res:"<<res<<endl;
    cout<<"hello world"<<endl;
    return 0;
}
// [17:26] Pingjiang Wang
    
// Input String: 123123412345 Output String: 111222333445
// ​[17:27] Pingjiang Wang
    
// Input String: 213123412345 Output String: 222111333445
// 