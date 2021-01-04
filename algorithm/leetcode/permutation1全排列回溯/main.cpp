//
//  main.cpp
//  permutation1全排列
//
//  Created by ChengWang on 3/23/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct cmp{
    bool operator()(char a, char b){
        return a<b;
    }
};

void permuation(vector<string> & v, string & s){
    do{
        v.push_back(s);
//        cout<<s<<endl;
//    }while(next_permutation(s.begin(),s.end()));
    }while(next_permutation(s.begin(),s.end(), cmp()));
}

int main(int argc, const char * argv[]){
    // insert code here...
    std::cout << "Hello, World!\n"<<endl;
    vector<string> v;
    string s("abd");
    permuation(v, s);
    for(auto &s: v)
        cout<<s<<endl;
    cout<<endl;
    return 0;
}


