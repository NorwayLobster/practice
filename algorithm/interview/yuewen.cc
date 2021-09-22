/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型
     */
    int sumNumbers(TreeNode* root) {
        // write code here
        if(nullptr==root) return 0;
        if(0==root->val) return 0;
        int res=0;
        int prefixSum=0;
        handle(root,res,prefixSum);
        return res;
    }
    void handle(TreeNode* root, int& res, int prefixSum){
        if(nullptr==root->left && nullptr==root->right){
           res+=prefixSum*10+root->val;
            return ;
        }
        int val=root->val;
        prefixSum=prefixSum*10+val;
        if(nullptr!=root->left)
            handle(root->left, res,prefixSum);
        if(nullptr!=root->right)
            handle(root->right, res,prefixSum);
    }
};