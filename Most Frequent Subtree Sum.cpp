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
    int dfs(TreeNode* root , vector<int>&sol){
        if(root == NULL)return 0;
        int left = dfs(root->left,sol);
        int right = dfs(root->right,sol);

        int sum = left + right + root->val;
        sol.push_back(sum);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        //for every single node i have to calculate the entire sum of its left and its right
        vector<int>sol;
        int temp = dfs(root,sol);
        map<int,int>mp;
        for(int i=0 ; i<sol.size() ; i++){
            mp[sol[i]]++;
        }
        int maxi=INT_MIN;
        for(auto it:mp){
            maxi = max(maxi , it.second);
        }
        vector<int>ans;
        for(auto it:mp){
            if(it.second == maxi){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};