/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        string s = "";
        if(root == NULL) return s;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL) s.append("#,");
            else s.append(to_string(node->val) + ',');
            if(node != NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s(data);
        string str = "";
        if(data.size() == 0) return NULL;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode * curr = q.front();
            q.pop();
            
            getline(s,str,',');
            if(str == "#") curr->left = nullptr;
            else{
                TreeNode* node = new TreeNode(stoi(str));
                curr->left = node;
                q.push(node);
            }
            
            getline(s,str,',');
            if(str == "#") curr->right = nullptr;
            else{
                TreeNode* node = new TreeNode(stoi(str));
                curr->right = node;
                q.push(node);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));