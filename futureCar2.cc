//c++
struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
};
struct retInfo{
    int min_val;
    int max_val;
    bool isValid;
    retInfo()
    :min_val(0)
    ,max_val(0)
    ,isValid(false)
    {}
    retInfo(int a,int b,bool flag)
    :min_val(a)
    ,max_val(b)
    ,isValid(false)
    {}
 };
 retInfo handle(TreeNode* root){
     //step0: exit
     if(nullptr==root->left && nullptr==root->right) return retInfo(root->val, root->val,true);
     retInfo ret(root->val,root->val);
     retInfo ret1;
     retInfo ret2;
     //step1: left
     if(nullptr!=root->left){
         ret1=handle(root->left);
         if(false==ret1.isValid){
             ret.isValid=false;
             return ret;
         }
     }
     //step2: right
     if(nullptr!=root->right){
         ret2=handle(root->right);
         if(false ==ret2.isValid){
             ret.isValid=false;
             return ret;
         }
     }
     //step3: mantain info
     if( nullptr!=root->left && ret1.max_val<root->val){
           ret.min_val=ret1.min_val;
           ret.isValid=true;
      }
      if(nullptr!=root->right && root->val<ret2.min_val){
           ret.isValid=ret.isValid;
           ret.max_val=ret2.max_val;
      }
     return ret;
 }
bool is_valid_bst(TreeNode* root){
    if(nullptr==root) return true;
    auto ret=handle(root);
    return ret.isValid;
}
