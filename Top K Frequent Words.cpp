bool helper(pair<string, int> &p1, pair<string, int> &p2)
{
    if(p1.second == p2.second)
        return p1.first < p2.first;
    
    return p1.second > p2.second;
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        int mx_freq = 0;
        map<string, int> mp;
        for(auto &i : words)
            mx_freq = max(mx_freq, ++mp[i]);
        
        vector<pair<string, int>> v;
        for(auto &i : mp)
            v.push_back(i);
        
        sort(v.begin(), v.end(), helper);
        
        vector<string> ans;
        for(auto &i : v)
        {
            if(!k)
                break;
            
            ans.push_back(i.first), k--;
        }
        
        return ans;
    }
};