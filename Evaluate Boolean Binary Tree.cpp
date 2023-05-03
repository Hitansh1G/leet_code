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
    bool helper(TreeNode* node){
        if(node==NULL )
            return false;
        else if(node->val == 0){
            return false;
        }
        else if(node->val==1){
            return true;
        }
        else if(node->val==2){
            return helper(node->left) or helper(node->right);
        }
        else if(node->val==3){
            return helper(node->left) and helper(node->right);
        }
        return false;
    }
    bool evaluateTree(TreeNode* root) {
//         if(root==NULL){
//             return false;
//         }
        
//         bool left = evaluateTree(root->left);
//         bool right = evaluateTree(root->right);
//         if(root->left->left == NULL || root->left->right==NULL){
//             int temp = root->val;
//             if(temp==2){
//                 return left or right;
//             }
//             else return left and right;
//         }
//         return false;
        // if(root==NULL){
        //     return false;
        // }
        // if(root->val==0){
        //     return false;
        // }
        // if(root->val==1){
        //     return true;
        // }
        // if(root->val==2){
        //     return evaluateTree(root->left) or evaluateTree(root->right);
        // }
        // if(root->val==3){
        //     return evaluateTree(root->left) and evaluateTree(root->right);
        // }
        if(root==NULL){
            return false;
        }
        return helper(root);
    }
};