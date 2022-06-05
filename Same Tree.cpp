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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        else if(p != NULL && q == NULL) return false;
        else if(p == NULL && q != NULL) return false;
        else{
            int val1,val2;
            val1 = p->val;
            val2 = q->val;
            return (val1 == val2 and isSameTree(p->right,q->right) and isSameTree(p->left,q->left));
            
            //if(p->val == q->val)
            //val1 = (isSameTree(p->right,q->right))
            
        }
        
    }
};