
// 你必须定义一个 `main()` 函数入口。
#include <iostream>
using namespace std;
class Solution {
public:
  //time, O(max(len1, len2)), space, O(max(len1,len2))
    string addBinary(string a, string b) {
        int len1=a.size();
        int len2=b.size();
      //step0: init:
      if(0==len1 && 0==len2) return "";
      if(0==len1){
        return b;
      }
      if(0==len2){
        return a;
      }
      //step1: 
      int carry=0;
      string res;
      int left1=0;
      int left2=0;
      while(left1<len1 || left2<len2){
          int a1= left1<len1?a[left1]-'0':0;
          int b1= left2<len2?b[left2]-'0':0;
          int sum=a1+b1+carry;
          int cur=sum%2;
          carry=sum/2;
          res.push_back(cur+'0');
        left1++;
        left2++;
      }
      if(carry>0){
        res.push_back(carry+'0');
      }
      return res;
    }
};
int main()
{
  cout << "Hello, World!" << endl;
  string a="0101";
  string b="1101";
  Solution s;
  string res=s.addBinary(a,b);
  cout<<"res:"<<res<<endl;
  return 0;
}