class Solution {
public:
    bool areIdentical(TreeNode* r1, TreeNode* r2){
        if(r1 == NULL && r2 == NULL) return true;
        if(r1 == NULL || r2 == NULL )return false;
        return (r1->val == r2->val and areIdentical(r1->left, r2->left) and areIdentical(r1->right, r2->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(root==NULL || subroot==NULL) return false;
        if(root==NULL && subroot==NULL) return true;
        if(areIdentical(root,subroot)) return true;
        return isSubtree(root->left, subroot) or isSubtree(root->right, subroot);
    }
};