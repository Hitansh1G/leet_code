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
    TreeNode* f(TreeNode* root, int val, int depth,int level){
        if(root){
            if(level==depth-1){
                TreeNode* left=root->left;
                TreeNode* right=root->right;
                root->left=new TreeNode(val);
                root->right=new TreeNode(val);
                root->left->left=left;
                root->right->right=right;
            }
            f(root->left,val,depth,level+1);
            f(root->right,val,depth,level+1);
            return root;
        }
        return nullptr;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        
        return f(root,val,depth,1);
    }
};