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
bool isLeaf(TreeNode* node){
    if(node->left == NULL && node->right==NULL){
        return true;
    }
    return false;
}
 
void addLeftBound(TreeNode * root, vector<int>& ans){
    root = root->left;
    while(root!=NULL){
        if(!isLeaf(root)) ans.push_back(root->val);
        if(root->left !=NULL) root = root->left;
        else root = root->right;
    }
}
 
void addRightBound(TreeNode * root, vector<int>& ans){
    root = root->right;
    stack<int> stk;
    while(root!=NULL){
        if(!isLeaf(root)) stk.push(root->val);
        if(root->right !=NULL) root = root->right;
        else root = root->left;
    }
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }
}
void addLeaves(TreeNode * root, vector<int>& ans){
    if(root==NULL){
        return;
    }
    if(isLeaf(root)){
        ans.push_back(root->val); 
        return;
    }
    addLeaves(root->left,ans);
    addLeaves(root->right,ans);
}
vector<int> binaryTreeBoundaryTraversal(TreeNode* root) {
    vector<int> ans;
    if(root==NULL) return ans;
    if(!isLeaf(root)) ans.push_back(root->val); 
    addLeftBound(root,ans);
    addLeaves(root,ans);
    addRightBound(root,ans);
    
    return ans;
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