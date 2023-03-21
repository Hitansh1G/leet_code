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
    void insert(TreeNode* & root,int x){
        if(root==NULL){
            root= new TreeNode(x);
            return ;
        }
        else if(root->val<x){
          insert(root->right,x);
        }
        else if(root->val>x){
            insert(root->left,x);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=new TreeNode(preorder[0]);
        TreeNode* temp=root;
        for(int i=1 ; i<preorder.size() ; i++){
            insert(temp,preorder[i]);
        }
        return root;
    }
};