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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);
        bool ltr = true;
        int i;
        while(!q.empty()) {
            int s = q.size();
            vector<int> curLevel(s);
            for(i=0; i < s; i++) {
                TreeNode* cur = q.front();
                q.pop();
                int index = ltr ? i : s-1-i;
                curLevel[index] = cur->val;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                
            }
            if(!ltr) ltr = true;
            else ltr = false;
            res.push_back(curLevel);
        }
        return res;
    }
};