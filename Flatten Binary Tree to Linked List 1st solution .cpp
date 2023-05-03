class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* pre=root;
        while(pre){
            if(pre->left){
            TreeNode* pos=pre->left;
            
            while(pos->right){
                pos=pos->right;
            }
            pos->right=pre->right;
            pre->right=pre->left;
            pre->left=NULL;
            }
            pre=pre->right;
        }
    }
};