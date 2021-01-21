/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2021-01-21 10:42:49
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-21 10:43:16
 * @FilePath: /practice/algorithm/interview/stackRanking头条二面.cc
 */
class Solution
{
public:
  /**
     * sort a stack
     * @param sta int整型vector the stack
     * @return int整型vector
     */
  vector<int> sortstack(vector<int> &sta)
  {
    // write code here
    int len = sta.size();
    vector<int> res(len, 0);
    int i = 0;
    if (sta.empty())
      return res;
    int j = len; //
    res[--j] = sta[i++];
    while (i <= len - 1)
    {
      int cur = sta[i];
      i++;
      while (j <= len - 1 && cur < res[j])
      {
        sta[--i] = res[j++];
      }
      res[--j] = cur;
    }
    return res;
  }
}