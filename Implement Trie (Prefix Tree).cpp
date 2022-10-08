class TrieNode{
public :
    bool end = false;
    TrieNode * childs[26];
    TrieNode(){
        for(int i = 0; i <26; i++)
            childs[i] = NULL;
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        int idx = 0;
        TrieNode *node = root;
        for(auto c: word) {
            idx = c-'a';
            if(!node->childs[idx])
                node->childs[idx] = new TrieNode();
            node = node->childs[idx];
        }
        node->end = true;
    }
    
    bool search(string word) {
        int idx = 0;
        TrieNode *node = root;
        for(auto c : word) {
            idx = c-'a';
            if(!node->childs[idx])
                return false;
            node = node->childs[idx];
        }
        return node->end;
    }
    
    bool startsWith(string prefix) {
        int idx = 0;
        TrieNode *node = root;
        for(auto c : prefix) {
            idx = c-'a';
            if(!node->childs[idx])
                return false;
            node = node->childs[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */