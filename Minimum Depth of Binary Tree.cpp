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
    int height(TreeNode* root){
        if(root == NULL )return 0;
        if(!root->left)return 1+height(root->right);
        if(!root->right) return 1+height(root->left);
        return min (height(root->left) , height(root->right))+1;
    }
    int minDepth(TreeNode* root) {
        if(root==NULL)return 0;
        // int x = height(root->left);
        // int y = height(root->right);

        // return 1+min(x,y);
        return height(root);

    }
};