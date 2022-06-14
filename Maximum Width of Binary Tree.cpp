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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int ans=0;
        while(!q.empty()){
            int n = q.size();
            int s = q.front().second;
            int e = q.back().second;
            ans = max(ans,e-s+1);
            while(n--) {
                int p = q.front().second - s;
                TreeNode* temp = q.front().first; 
                q.pop();
                
                if(temp -> left) q.push({temp -> left, (long long)p * 2 + 1});
                if(temp -> right) q.push({temp -> right, (long long)p * 2 +  2});
            }
        }
        return ans;
    }
};