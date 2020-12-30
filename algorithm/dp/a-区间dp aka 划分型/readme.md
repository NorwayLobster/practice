<!--
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2020-12-27 20:51:12
 * @LastEditors: ChengWang
 * @LastEditTime: 2020-12-27 20:58:57
 * @FilePath: /practice/algorithm/dp/a-区间dp aka 划分型/readme.md
-->

# 题型总结
  区间dp的关键点
   1. 分割点k: 一定存在一个断点，使得断开的两段最优值推出整段的最优值: 
    OPT(i,j)=max{OPT(i,k),OPT(k+1,j)}+wij;其中，k在[i,j)之间
   2. 计算顺序
      依次递增链长，先计算小区间，在计算大区间
  