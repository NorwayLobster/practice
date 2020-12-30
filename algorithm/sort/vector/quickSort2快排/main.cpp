//
//  main.cpp
//  quickSort快排
//
//  Created by ChengWang on 3/23/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
using namespace std;
void generateRandomArray(vector<int> &v, int maxSize, int maxValue);
void print(vector<int> & v);

//联系 荷兰国旗partition
pair<int, int> partition(vector<int> &v, int left, int right){
    int less = left-1;
    int pivot = right;
    int more = right;
    int cur=left;
    while(cur < more){
       if(v[cur]<v[pivot]){ swap(v[++less], v[cur++]); }
       else if(v[cur]>v[pivot]){ swap(v[cur], v[--more]); }
       else
             ++cur;
    }
    swap(v[cur], v[pivot]);
//    return make_pair(less+1, more-1);
    return make_pair(less+1, cur);
}

void quickSort(vector<int> &v, int left, int right ){
    if(left>=right) return ;
    pair<int, int > p = partition(v, left, right);
    quickSort(v, left, p.first-1 );
    quickSort(v, p.second+1, right);
    return;
}
int test0(int argc, const char * argv[]) {
        // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> v(5,0);
    for(int i=0; i<5; i++){
        cin>>v[i];
    }
    quickSort(v, 0, v.size()-1);
    copy(v.begin(),v.end(), ostream_iterator<int> (cout, " "));
    cout<<endl;
    return 0;
}






int main(int argc, const char * argv[]) {
        // insert code here...
    std::cout << "Hello, quickSort!\n";
    int testTime = 10;
    int maxSize = 50;
    int maxValue = 100;
    vector<int> v;
    v.reserve(maxSize);
    bool succeed = true;
    srand((unsigned)time(NULL));
    for (int i = 0; i < testTime; i++) {
        v.clear();//用完后每次都要清理
        generateRandomArray(v, maxSize, maxValue);
        vector<int> v1(v);
        vector<int> v2(v);
        print(v1);
        print(v2);
        sort(v1.begin(),v1.end());
            //        quickSort_v1(v2, 0, v.size()-1);
        quickSort(v2, 0, v.size()-1);
        print(v1);
        print(v2);
        cout<<endl;
        cout<<endl;
        if (!equal(v1.begin(), v1.end(), v2.begin())){
            succeed = false;
            print(v1);
            print(v2);
            break;
        }
    }
    cout<<(succeed ? "Nice!" : "Fucking fucked!");
    cout<<endl;
    
    return 0;
}

void generateRandomArray(vector<int> &v, int maxSize, int maxValue){
    for(int i = 0; i < maxSize;i++ )
        v.push_back(rand()%(maxValue-10)+10);
}

void print(vector<int> & v)
{
    copy(v.begin(), v.end(), ostream_iterator<int> (cout," "));
    std::cout << '\n';
}

