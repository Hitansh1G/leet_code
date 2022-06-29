class Solution {
public:
    
    void tre(TreeNode* r, stack<TreeNode*> &s){
        if(r->left == NULL && r->right == NULL){
            s.push(r);
            return;
        }
        //take node
        s.push(r);
        //goleft
        if(r->left != NULL)
            tre(r->left,s);
        //go right
        if(r->right != NULL)
            tre(r->right,s);
    }
    
    void flatten(TreeNode* r) {
        if(r == NULL) return;
        if(r->left == NULL && r->right == NULL) return;
        TreeNode* t = r;
        stack<TreeNode*> s;
        tre(t,s);
        t = s.top();
        t->right = NULL;
        t->left = NULL;
        s.pop();
        while(!s.empty()){
            TreeNode* x = s.top();
            x->right = t;
            x->left = NULL;
            s.pop();
            t = x;
        }
    }
};