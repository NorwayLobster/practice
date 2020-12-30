//
//  main.cpp
//  二分查找
//
//  Created by ChengWang on 12/17/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> v1={1,2,3,1,4,0,5,4,4,4,4,10,5};
    cout<<is_sorted(v1.begin(),v1.end())<<endl;
    partial_sort(v1.begin(),v1.begin()+4,v1.end());
//    partial_sort(<#_RandomAccessIterator __first#>, <#_RandomAccessIterator __middle#>, <#_RandomAccessIterator __last#>, <#_Compare __comp#>)
    for(auto e:v1)
        printf("%d_",e);

    //    sort(v1.begin(),v1.end());
    //    stable_sort(v1.begin(),v1.end());
//    stable_sort(<#_RandomAccessIterator __first#>, <#_RandomAccessIterator __last#>, <#_Compare __comp#>)
    cout<<is_sorted(v1.begin(),v1.end())<<endl;
    cout<<binary_search(v1.begin(),v1.end(),100)<<endl;
//    bool binary_search(<#_ForwardIterator __first#>, <#_ForwardIterator __last#>, <#const _Tp &__value_#>, <#_Compare __comp#>)
    for(auto e:v1)
        printf("%d_",e);
    printf("\n");
    return 0;
}

