/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2021-01-28 08:39:40
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-28 08:40:41
 * @FilePath: /practice/algorithm/interview/decodeCount-头条-三面.cc
 */

/*
用 1-26 编码 A-Z，求输入数组的解码方案数
1) 数组每个元素都是 0-9，长度 N ~10000
2) 0 只能作为 10、20 被解码
3) 如果无法解码，返回0

示例
输入
1 2 3 4 5
解码
A B C D E
L     C D E
A W    D E
输出
3

int DecodeCount(const vector<int>& nums) {}
*/

#include <iostream>
#include<vector>
using namespace std;
int DecodeCount(const vector<int>& nums) {
    int len=nums.size();
    if(len==0) return 0;
    int pre=0;
    int prepre=1;
    if(nums[0]==0){
        return 0;
    }
    pre=1;
    int cur=0;
    for(int i=1;i<len;++i){
        int val=-1;
        if(nums[i-1]!=0){
          val=nums[i-1]*10+nums[i];          
        }
        if(val>0 && val<=26 && nums[i]>0){
            cur=pre+prepre;
        }else if(nums[i]>0){
            cur=pre;
        }else if(val>0 && val<=26){
            cur=prepre;
        }else{
            return 0;
        }
        prepre=pre;
        pre=cur;
    }
    return pre;
}

int main() {
    //int a;
    //cin >> a;
//    vector<int> v={1,2,3,4,5,6};/
 //   vector<int> v={0,2,3,4,5,6};
 //   vector<int> v={0,0,3,4,5,6};
//   vector<int> v={1,0,0,4,5,6};
//   vector<int> v={1,2,3,4,5,0};
   vector<int> v={1,2,3,4,0,0};
    int res=DecodeCount(v);
    cout<<"res:"<<res<<endl;
    cout << "Hello World!" << endl;
}
