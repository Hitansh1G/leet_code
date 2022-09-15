class Solution {
private:
    void reduceFreq(unordered_map<int, int> &mp, int val){
        mp[val]--;
        
        if(mp[val] == 0)
            mp.erase(val);
    }
    
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n & 1) return {};
        sort(changed.begin(), changed.end());
        unordered_map<int, int> mp;
        for(auto &val : changed){
            mp[val]++;
        }
        vector<int> res;
        for(auto &val : changed){
            if(mp[val] == 0) continue;
            reduceFreq(mp, val);
            if(mp[val * 2] > 0){
                reduceFreq(mp, val * 2);
            }
            else if(mp[val / 2] > 0){
                reduceFreq(mp, val / 2);
            }
            else{
                return {};
            }
            res.push_back(val);
        }
        
        
        return res;
    }
};