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


vector<int> topViewBinaryTree(TreeNode* root) {
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    map<int,int>mp;
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});
    while(q.empty()==false){
        auto it = q.front();
        q.pop();
        TreeNode* node = it.first;
        int line = it.second;
        if(mp.find(line) == mp.end()){
            mp[line] = node->val;
        }
        if(node->left != NULL){
            q.push({node->left,line-1});
        }
        if(node->right!=NULL){
            q.push({node->right,line+1});
        }
    }
    for(auto it:mp){
        ans.push_back(it.second);
    }
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