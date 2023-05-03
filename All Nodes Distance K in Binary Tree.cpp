/*
what if we were asekd to find downwards nodes that re k distance from target ?
we would have made 2 recursive calls from target i.e. one for the left side and another for the right side and would have decreased distance until it becomes 0. if it becomes 0 then would have added it to the ans (vector)
but in this question we have to find even the upwrds nodes that are k distance from the target 
so it means we have to move iupwards as well , so for that we will somply make calls for the parent of the current node/

find the parent of all thr nodes and store it in a hashmap 
now make recusive calls only if the current node isnt visited , to find the k distance nodes from target
now trverse downwards by making 2 recusive calls one for root->left and another for root->right and keeep descrementing the distance node from target
Now , traverse downward by making two recursive calls one for root->left and another for root->right and keep decrementing the distance(i.e. k).
Now,traverse upward by making call for the parent of the current node. (i.e. parent[root]).
Base Conditions :-

if root is NULL , return
if distance becomes 0,return


*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
     //function to find all nodes at distance k from target
    void findDistanceKNodes(TreeNode* root,int distance,unordered_map<TreeNode*,TreeNode*>&parent,
                           vector<int>&ans,unordered_map<TreeNode*,bool>&vist)
    {
        if(root == NULL || vist[root] == true)
            return;
        
        if(distance == 0)
            ans.push_back(root->val);
        
        if(vist[root] != true)
        {
            vist[root] = true;
            //downward traversal
            findDistanceKNodes(root->left,distance-1,parent,ans,vist);//left downward
            findDistanceKNodes(root->right,distance-1,parent,ans,vist);//right downward
            //upward traversal
            findDistanceKNodes(parent[root],distance-1,parent,ans,vist);        
        }       
        
    }
    
    
     //function to find parent of all nodes
    void findParent(TreeNode* root,TreeNode* currentParent,unordered_map<TreeNode*,TreeNode*>&parent)
    {
        if(root == NULL)
            return;
        
        parent[root] = currentParent;
        findParent(root->left,root,parent);
        findParent(root->right,root,parent);
    }
    
    
    //start
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        unordered_map<TreeNode*,TreeNode*>parent; //to store parent of all nodes
        findParent(root,NULL,parent);
        
        /*for(auto i:parent)
            cout<<i.first->val<<" : "<<i.second->val<<endl;*/
        
        vector<int>ans; //to store all the nodes that have k-distance from target
        unordered_map<TreeNode*,bool>vist;
        findDistanceKNodes(target,k,parent,ans,vist);
        
    return ans;
    }
};

