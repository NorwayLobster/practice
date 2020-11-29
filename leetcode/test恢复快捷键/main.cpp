//
//  main.cpp
//  test恢复快捷键
//
//  Created by ChengWang on 3/6/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> v;
    for(int i=0;i<10;++i)
    {
        v.push_back(rand()%((100-10)+10));
    }
    
    copy(v.begin(),v.end(), ostream_iterator<int> (cout," "));//输出流迭代器的无名对象，关联到输出流cout对象上。
    cout<<endl;
    return 0;
    
}
