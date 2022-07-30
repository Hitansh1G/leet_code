class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        if(n<10){
            return {};
        }
        unordered_map<string, int> cache;
        for(int i=0; i<n-9; i++){
            cache[s.substr(i,10)]+=1;
        }
        vector<string> ans;
        for(auto it : cache){
            if(it.second>1) ans.push_back(it.first);
        }
        return ans;
    }
};