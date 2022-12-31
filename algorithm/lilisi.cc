#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//12345
//target: 3
//time, O(N), space, O(1)
void unsortedArrayUnique(vector<int>& v, int target){
    int len=v.size();
    int left=0;
    int right=0;
    while(right<len){
        if(v[right]!=target){
            v[left]=v[right];
            left++;
        }
        right++;
    }
}
int main(){
    cout<<"hello world"<<endl;
    return 0;
}
