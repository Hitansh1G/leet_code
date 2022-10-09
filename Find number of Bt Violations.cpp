#include "../crio/cpp/ds/TreeNode/TreeNode.hpp"

/*
Definition for TreeNode
class TreeNode {
public:
    long val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
    TreeNode (long x) {
        val = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
}

Use new TreeNode(data) to create new Node
*/
// vector<int>inOrder(TreeNode* root){
// 	if (root == NULL){
// 		vector<int>temp;
// 		return temp;
// 	}
// 	vector<int>a = inOrder(root->left);
// 	vector<int>b = inOrder(root->right);

// 	a.push_back(root->val);
// 	for (int i = 0; i < b.size(); i++){
// 		a.push_back(b[i]);
// 	}
// 	return a;
// }
int height(TreeNode* root){
	if(root == NULL){
		return 0;
	}
	return max(height(root->left),height(root->right))+1;
}
int findNumberOfBtVoilations(TreeNode* root) {
	if(root==NULL)return 0;
	int a = findNumberOfBtVoilations(root->left);
	int b = findNumberOfBtVoilations(root->right);
	int lh = height(root->left);
	int rh = height(root->right);
	if(abs(lh-rh)>1){
		return a+b+1;
	}
	return a+b;
}
/* 
Crio Methodology

Milestone 1: Understand the problem clearly
1. Ask questions & clarify the problem statement clearly.
2. Take an example or two to confirm your understanding of the input/output & extend it to test cases
Milestone 2: Finalize approach & execution plan
1. Understand what type of problem you are solving.
     a. Obvious logic, tests ability to convert logic to code
     b. Figuring out logic
     c. Knowledge of specific domain or concepts
     d. Knowledge of specific algorithm
     e. Mapping real world into abstract concepts/data structures
2. Brainstorm multiple ways to solve the problem and pick one
3. Get to a point where you can explain your approach to a 10 year old
4. Take a stab at the high-level logic & write it down.
5. Try to offload processing to functions & keeping your main code small.
Milestone 3: Code by expanding your pseudocode
1. Make sure you name the variables, functions clearly.
2. Avoid constants in your code unless necessary; go for generic functions, you can use examples for your thinking though.
3. Use libraries as much as possible
Milestone 4: Prove to the interviewer that your code works with unit tests
1. Make sure you check boundary conditions
2. Time & storage complexity
3. Suggest optimizations if applicable
*/