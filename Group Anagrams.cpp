class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> ump;
        
        for(auto word:strs){
            string temp = word;
            sort(word.begin(), word.end());
            ump[word].push_back(temp);
        }
        
        for(auto it:ump){
            result.push_back(it.second);
        }
        
        return result;
    }
};