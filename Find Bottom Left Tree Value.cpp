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
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL)return 0;
        queue<TreeNode*>q;
        q.push(root);
        int res = -1;
        while(!q.empty()){
            int n=q.size();
            res = q.front()->val;
            for(int i=0 ; i<n ; i++){
                auto p = q.front();
                q.pop();
                if(p->left != NULL)q.push(p->left);
                if(p->right != NULL)q.push(p->right);
            }
        }
        return res;
    }
};