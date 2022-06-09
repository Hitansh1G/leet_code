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
    // bool helper(TreeNode*root , int max , int min){
    //     if(root == NULL) return true;
    //     if(root->val >= min && root->val <= max){
    //         bool left = helper(root->left ,root->val ,min);
    //         bool right = helper(root->right, max , root->val);
    //         return left && right;
    //     }
    //     return false;
    // }
    bool helper(TreeNode* root , TreeNode* min , TreeNode* max){
        if(root == NULL) return true;
        if(min != NULL ){
            if(root->val >= min->val) return false;
        }
        if(max !=NULL ){
            if(root->val <= max->val) return false;
        }
        return helper(root->left, root , max) && helper(root->right , min , root );
    }
    bool isValidBST(TreeNode* root) {
        // return helper(root,INT_MAX,INT_MIN);
        return helper(root , NULL , NULL );
    }
};