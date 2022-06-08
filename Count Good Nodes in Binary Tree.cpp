/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count=0;
    int helper(TreeNode* root , int n){
        if(root==NULL) return 0;
        n = max(n,root->val);
        if(root->val >= n ) count++;
        helper(root->left,n);
        helper(root->right,n);
        return count;
    }
    
    
    int goodNodes(TreeNode* root) {
        return helper(root,INT_MIN);
        
    }
};