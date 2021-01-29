/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2021-01-26 13:07:52
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-26 15:34:39
 * @FilePath: /practice/algorithm/interview/knapsack正好装满-科大讯飞.cc
 */

/*
1,2,3 三个数字无限次使用，组成正整数N，求方案个数以及所有具体方案
装载问题: 正好装满的方案数以及所有具体方案。
找零钱问题: 求所有找零钱的方案数以及所有具体方案，以及硬币数最少的方案(最优方案)
无限制背包问题: 正好装满的方案数及所有具体方案
注意和爬楼梯问题有本质区别: 装在问题是组合问题
*/
//dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
//1: 1
//2: 1,1; 2
//3: 1,1,1; 2,1;3
//4: 1,1,1,1; 2,1,1;3,1;
//   1,1,2; 2,2; 
//   1,3;