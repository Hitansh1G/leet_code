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
    void helper(TreeNode* root , int l ,vector<int>&ans ){
        if(!root) return ;
        if(l == ans.size()) {
            ans.push_back(root->val);
        }
        if(root->right != NULL){
            helper(root->right , l+1 , ans);
        }
        if(root->left != NULL){
            helper(root->left , l+1 , ans);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        helper(root,0,ans);
        return ans;
    }
};