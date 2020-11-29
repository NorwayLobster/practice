//
//  main.cpp
//  std::merge()与set_union()
//
//  Created by ChengWang on 12/17/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> v1={1,2,3,4,10,10};
    vector<int> v2={2,4,5,9,1};
    vector<int> v4={2,4};
//    vector<int> v3;
    vector<int> v3(20,0);
//    merge(v1.begin(),v1.end(),v2.begin(),v2.end(), v3.begin());
    set_union(v1.begin(),v1.end(),v2.begin(),v2.end(), v3.begin());
//    set_intersection(v2.begin(),v2.end(),v1.begin(),v1.end(), v3.begin());
//    set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(), v3.begin());//v1中不在v2的元素的集合
//    set_difference(v2.begin(),v2.end(),v1.begin(),v1.end(), v3.begin());//v2中不在v1中的元素的集合
    //set_union()的集合-set_intersection()的集合
//    set_symmetric_difference(v2.begin(),v2.end(),v1.begin(),v1.end(), v3.begin());
 //   cout<<includes(v2.begin(),v2.end(),v4.begin(),v4.end());//v2是否包括v4的所有元素，集合包含关系
    sort(v3.begin(),v3.end());
    auto iter=unique(v3.begin(),v3.end());
    cout<<endl;
    cout<<*(iter-1)<<endl;
    
    set<int> s;
    s.insert(1);
    s.insert(11);
    s.insert(11);
    s.insert(12);
    cout<<s.size()<<endl;
   //error: sort(s.begin().s.end());
   //error:  unique(s.begin().s.end());
//    includes(<#_InputIterator1 __first1#>, <#_InputIterator1 __last1#>, <#_InputIterator2 __first2#>, <#_InputIterator2 __last2#>, <#_Compare __comp#>)
//    set_symmetric_difference(<#_InputIterator1 __first1#>, <#_InputIterator1 __last1#>, <#_InputIterator2 __first2#>, <#_InputIterator2 __last2#>, <#_OutputIterator __result#>)
//    set_intersection(<#_InputIterator1 __first1#>, <#_InputIterator1 __last1#>, <#_InputIterator2 __first2#>, <#_InputIterator2 __last2#>, <#_OutputIterator __result#>, <#_Compare __comp#>)
//    set_difference(<#_InputIterator1 __first1#>, <#_InputIterator1 __last1#>, <#_InputIterator2 __first2#>, <#_InputIterator2 __last2#>, <#_OutputIterator __result#>, <#_Compare __comp#>)
//    set_union(_InputIterator1 __first1, <#_InputIterator1 __last1#>, <#_InputIterator2 __first2#>, <#_InputIterator2 __last2#>, <#_OutputIterator __result#>, <#_Compare __comp#>)
    for(auto e:v3)
        printf("%d-",e);
//    merge(<#_InputIterator1 __first1#>, <#_InputIterator1 __last1#>, <#_InputIterator2 __first2#>, <#_InputIterator2 __last2#>, <#_OutputIterator __result#>, <#_Compare __comp#>)
    return 0;
}
