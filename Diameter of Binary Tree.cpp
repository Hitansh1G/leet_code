class Solution {
public:
    int height(TreeNode* root , int& d){
        if(root==NULL) return 0;
        
        int left = height(root->left,d);
        int right = height(root->right,d);
        d=max(d,left+right);
        
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        
        int d = 0;
        height(root,d);
        return d;
    }
};