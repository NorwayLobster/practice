#include<iostream>
// #include<bits/stdc++.h>
//1. timestamp
//2. kind/type
// data structure in cache, getTopN(time1,time2,n)
//inputStream:
#include<vector>
#include<pair>
//1. get 
//2. 
//3. 
using namespace std;
vector<int> getTopNEventType(StreamType& inputStream, int time1, int time2, int n){
    //step1: get input event between time1 and time2;
    vector<pair<int,int>> inputEvents=inputStream.getEventTime(time1,time2);//timestamp, event type
    int len=inputEvents.size();
    unordered_map<int,int> freHash;//event type index, fre
    //step2: collect info of them
    for(int i=0;i<len;++i){
        auto p=inputEvents[i];
        freHash[p.second]++;   
    }
    //step3: get top n fre event type;
    vector<pair<int,int> sortV(freHash.begin(),freHash.end());
    sort(sortV.begin(),sortV.end(),[]{});
}
int main(){
    cout<<"hello world"<<endl;

    

    return 0;
}