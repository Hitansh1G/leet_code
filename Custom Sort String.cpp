class Solution {
public:
    string customSortString(string order, string s) {
        vector<char> order_dict;
        vector<int> counting(26);
        string ans = "";
        for(auto &c : order) order_dict.push_back(c);
        for(auto &c : s) counting[c - 'a']++;
        for(auto &c : order_dict){
            while(counting[c - 'a'] > 0){
                ans += c;
                counting[c - 'a']--;
            }
        }
        for(int curr = 0; curr < counting.size(); curr++){
            while(counting[curr] > 0){
                ans += char('a' + curr);
                counting[curr]--;
            }            
        }
        
        return ans;
    }
};