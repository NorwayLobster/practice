//
//  main.cpp
//  for_each
//
//  Created by ChengWang on 11/26/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
class print{
public:
    void operator()(int a){
        printf("%d ",a);
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> v{1,23,2};
    for_each(v.begin(),v.end(),print());
    printf("\n");
    return 0;
}
