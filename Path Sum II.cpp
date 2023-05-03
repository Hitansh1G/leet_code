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
    void dfs ( TreeNode * root , int k , vector<int>&path , vector<vector<int>>&ans){
        if(root) {
            path.push_back(root->val);
            if(!root->right && !root->left &&  k == root->val){
                ans.push_back(path);
            }
            dfs(root->left , k - root->val ,path , ans);
            dfs(root->right , k - root->val , path , ans);
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int k) {
        vector<int>path ;
        vector<vector<int>>ans;
        dfs(root , k ,path , ans);
        return ans;
    }
};