/*
 * @Author: ChengWang(cheng.wang.801@gmail.com)
 * @Date: 2021-01-25 14:19:00
 * @LastEditors: ChengWang
 * @LastEditTime: 2021-01-25 14:48:24
 * @FilePath: /practice/algorithm/interview/leftSideofTree-爱奇艺一面.cc
 */

/**
         a                         <------
      c     b
  e     d   f  g
  l m j k 
  
  abf
  abd
  
  
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution{
  void scan(TreeNode *root, int h, vector<int> &views){
        //resize();
    if(root == nullptr) return;
      traverse(root, 0, views);
     }
  void traverse(TreeNode *root, int level, vector<int> &views){
    if (root == nullptr) return;
    if (views.size() > level){
      views[level] = root->val;
    }else{
      views.push_back(root->val);
    }
    traverse(root->left, level + 1, views);
    traverse(root->right, level + 1, views);
  }

  //way2:
    void scan_v2(TreeNode *root, int h, vector<int> &views){
  if(nullptr == root) return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()){
      int len = q.size();
      while(int i = 0; i < len; ++i){
        TreeNode *cur = q.top();
        q.pop();
        if (i == len - 1)
        {
          views.push_back(cur->val);
        }
        if (cur->left != nullptr)
        {
          q.push(cur->left);
        }
        if (cur->right != nullptr)
        {
          q.push(cur->right);
        }
      }
    }
  }
};