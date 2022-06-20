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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode *,int>> q;
        q.push({root,0});
        
        int i = 0,depth;
        
        while(!q.empty()){
            TreeNode *curNode = q.front().first;
            depth = q.front().second;
            q.pop();
            
            if(!curNode) continue;
            if(depth == i){
                i++;
                ans.push_back({});
            }
            
            ans[depth].push_back(curNode->val);
            
            q.push({curNode->left,depth + 1});
            q.push({curNode->right,depth + 1});
        }
        return ans;
    }
};