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
    TreeNode* construct(vector<int> &nums, int L, int R) {
        if(L > R) {
            return NULL;
        }
        int mid = L + (R-L)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = construct(nums, L, mid-1);
        root->right = construct(nums, mid+1, R);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return construct(nums,0,nums.size()-1);
    }
};