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
    string helper(TreeNode* node, unordered_map<string, int>& mp, vector<TreeNode*>& dupli) {
        if (!node) return "#"; 
        
        string left = helper(node->left, mp, dupli);
        string right = helper(node->right, mp, dupli);
        
        string s = left + "," + right + "," + to_string(node->val); 
        
        if (mp[s] == 1) dupli.push_back(node); 
        
        mp[s]++;
        return s;
    }
 vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mp; 
        vector<TreeNode*> dupli; 
        
        helper(root, mp, dupli); 
        
        return dupli;
    }
    
};