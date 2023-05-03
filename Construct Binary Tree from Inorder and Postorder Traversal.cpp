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
private:
    int postorderIndex;
    unordered_map<int,int> m;
    TreeNode* build(vector<int> postorder,int start,int end){
        // null root
        if(start>end or postorderIndex<0)
            return NULL;
        
        int x=postorder[postorderIndex--];

        TreeNode* root = new TreeNode(x);
        
        int inorderIndex=m[x];
        
        root->right=build(postorder,inorderIndex+1,end);
        root->left=build(postorder,start,inorderIndex-1);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        
        postorderIndex=n-1;
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        
        return build(postorder,0,n-1);
    }
};