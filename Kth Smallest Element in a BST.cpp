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
// class Solution {
// public:
//     void fillvec(TreeNode* root, vector<int> &vec){
//         // fill the vector with the elements of the tree
//         if(root==NULL){
//             return;
//         }
//         vec.push_back(root->val);
//         fillvec(root->left,vec);
//         fillvec(root->right,vec);
//     }
//     int helper(TreeNode* root,int k, vector<int> &vec){
//         //find the kth smallest from the vector
//         sort(vec.begin(),vec.end());
//         while(k!=0){
//             vec.pop_back();
//             k--;
//         }
//         int temp = vec[vec.size()-1];
//         return temp;
        
//     }
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int>vec;
//         fillvec(root,vec);
//         int temp = helper(root,k,vec);
//         return temp;
//     }
// };
class Solution {

public:

    int count_of_nodes=0;
	void inorder(TreeNode* root, int &k, int &ans){

		if(root==NULL)
			return;

		inorder(root->left, k, ans);
		count_of_nodes++;
		if(count_of_nodes==k)
			ans = root->val;
		inorder(root->right, k, ans);
	}

	int kthSmallest(TreeNode* root, int k) {
      
		int ans;
		inorder(root, k, ans);
		return ans;
	}
};