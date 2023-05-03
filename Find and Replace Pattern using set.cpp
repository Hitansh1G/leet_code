class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string p) {
        vector<string> ans;
        for(auto w:words){
            unordered_map<char,char> mp;
            unordered_set<char> s;
            if(p.size()!=w.size()){
                continue;
            }
            int n=p.size(),flag=1;
            for(int i=0 ; i<n ; i++){
                if(mp.count(w[i])){
                    if(mp[w[i]]!=p[i]){
                        flag=0;
                        break;
                    }
                }
                else{
                    if(s.count(p[i])){
                        flag=0;
                        break;
                    }
                    else{
                        mp[w[i]]=p[i];
                        s.insert(p[i]);
                    }
                }
            }
            if(flag){
                ans.push_back(w);
            }
        }
            return ans;
    }
};