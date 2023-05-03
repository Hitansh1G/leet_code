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
    TreeNode* helper (vector<int>& preorder, vector<int>& postorder,int *preIndex,int l, int h, int size){ 
        if (*preIndex >= size || l > h)
        return NULL;

        TreeNode* root = new TreeNode(preorder[*preIndex]);
        ++*preIndex;
        if (l == h)
            return root;
        int i;
        for (i = l; i <= h; ++i){ 
            if (preorder[*preIndex] == postorder[i])
            break;
        }
        if (i <= h){
            root->left = helper (preorder, postorder, preIndex,l, i, size);
            root->right = helper (preorder, postorder, preIndex, i + 1, h-1, size);
        }
        return root;
}
public:
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            int n=preorder.size();
            int preIndex=0;
            return  helper (preorder, postorder, &preIndex,0,n-1,n);
        }

};


