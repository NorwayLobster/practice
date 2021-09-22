#include<bits/stdc++.h>
using namespace std;
/**二叉树的层序遍历*/
/*
type Node struct{
    Val  int64
    Right *Node
    Left  *Node 
}
func LevelOrderTraversal(head *Node) [][]int64 {
}
*/
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
    :val(0)
    ,left(nullptr)
    ,right(nullptr)
    {}
    TreeNode(int a)
    :val(a)
    ,left(nullptr)
    ,right(nullptr)
    {}
};
//time, O(N), space, O(N), O(max_level_num_node)
vector<vector<int>> levelOrderTraversal(TreeNode* head){
    vector<vector<int>> res;
    if(nullptr==head) return res;
    queue<TreeNode*> q;
    q.push(head);
    vector<int> tmp;
    while(!q.empty()){
        tmp.clear();
        int len=q.size();
        for(int i=0;i<len;++i){
            auto cur=q.front();
            q.pop();
            tmp.push_back(cur->val);
            if(nullptr!=cur->left){
                q.push(cur->left);
            }
            if(nullptr!=cur->right){
                q.push(cur->right);
            }
        }
        res.push_back(tmp);
    }
    return res;
}

int main(){
    cout<<"hello world!"<<endl;
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);

    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);


vector<vector<int>>  res=levelOrderTraversal(root);
for(auto& tmp: res){
    for(auto e: tmp){
        cout<<e<<" ";
    }
    cout<<endl;
}
    //delete 
    return 0;
}