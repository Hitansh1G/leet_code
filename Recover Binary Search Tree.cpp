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
    TreeNode* first, *last, *prev;
public:
    
    void helper(TreeNode* root){
        if(root==NULL)return;
        helper(root->left);
        if(prev != NULL && (root->val < prev->val)){
            if(first == NULL){
                first = prev;
                last = root;
            }
            else last = root;
        }
        prev = root;
        helper(root->right);
    }
    void recoverTree(TreeNode* root) {
        // if(root==NULL)return;
        first = last = prev = NULL;
        helper(root);
        swap(first->val,last->val);
        
    }
};