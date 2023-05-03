class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<char, int> n2d{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        unordered_set<int> candidates;
        unordered_set<string> duplicates;
        int cur = 0;
        for (int i = 0; i < s.length(); i++){
            cur %= 1<<18;                
            cur = cur * 4 + n2d[s[i]];
            if (i < 9) continue;
            if (candidates.count(cur) > 0){
                duplicates.insert(s.substr(i-9, 10));
            }
            else{
                candidates.insert(cur);
            }
        }
        return vector<string>(duplicates.begin(), duplicates.end());
    }
};