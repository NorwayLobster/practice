/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2021-01-25 14:14:04
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-25 14:16:29
 * @FilePath: /practice/algorithm/interview/isSamePattern.cc蚂蚁金服.cc
 */
//评测题目: 无
// 同构字符串
// aabb, 0011
// abcba, 12321
// aabbcc, 223311
// abba, 0001 => false
 // a->2
//
//aabbcc, 223322

// a..x -> [0, 1, .. 25]
// xxyy -> [0, 0, 1, 1]
// aaxx -> [0, 0, 24, 24]
//time, O(NlogN), space, O(N)
 bool isSamePattern(const string& s1, const string& s2){
   int len1=s1.size();
   int len2=s2.size();
   if(len1!=len2) return false;
//   if(len1==0 || len2==0) return false;
   vector<int> res1;
   vector<int> res2;
   help(s1, res1);
   help(s2, res2);
   int cur1=0;
   int cur2=0;
   while(cur1<len1 && cur2<len2){
     if(res1[cur1++]!=res2[cur2++]){
       return false;
     }
   }
   return true;
}
void help(const string& s, vector<int>& res){
     map<char, int> dict;
  	 int len=s.size();
  	 int id=0;
  	 for(int i=0;i<len;++i){
       char cur=s[i];
       if(dict.end()!=dict.find(cur){
         res.push_back(dict[cur]);
       }else{
         dict[cur]=id;
         res.push_back(id);
         ++id;
       }
     }
}
