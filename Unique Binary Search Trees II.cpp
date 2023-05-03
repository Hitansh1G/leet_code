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
vector<TreeNode*> dp[9][9]; 
class Solution {
public:
    vector<TreeNode*> generateTrees(int n,int extra = 0) { 
        if(n==0)return {NULL}; 
        if(n==1){ 
            TreeNode *now = new TreeNode(1+extra); 
            return {now}; 
        }
        if(!dp[n][extra].empty())return dp[n][extra]; 
        vector<TreeNode*> &ans = dp[n][extra]; 
        
        for(int i=1;i<=n;i++){
            auto x = generateTrees(i-1,extra); 
            auto y = generateTrees(n-i,i+extra); 
            for(TreeNode* p:x){
                for(TreeNode* q:y){
                    TreeNode* nx = new TreeNode(i+extra); 
                    nx->left = p;
                    nx->right = q;
                    ans.push_back(nx);
                }
            }
        }
        return ans;
    }
};