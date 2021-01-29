/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2021-01-29 16:28:38
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-29 12:03:24
 * @FilePath: /practice/algorithm/interview/fib变形-遂原科技.cc
 */
/*
从1到2000都是1，2001开始, 每个数都是它前面2000个数的和
*/
//time, O(N), space, O(1) 
int f(int n){
  if(n<=2000) return n;
  vector<int> dp(2000+1,0);//以i下标结尾子数组的sum
  int n=2002;
  //或者用queue，也是能实现O(1)的空间复杂度
  for(int i=20001;i<=n;++i){
    int fi=dp[(i-1)%2000]-dp[(i-2000)%2000];
    dp[i%2000]=fi+dp[(i-1)%2000];
  }
}