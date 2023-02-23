class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string>word_Set(wordDict.begin(),wordDict.end());
        vector<vector<string>>dp(n+1,vector<string>());
        dp[0].push_back("");

        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<=n ;j++){
                //size_t found = str.find(str1);
                // if (found != string::npos)
                // cout << "First occurrence is " << found << endl;
                string temp = s.substr(i, j-i);
                if(word_Set.count(temp)){
                    for(auto x : dp[i]){
                        dp[j].emplace_back(x + (x == "" ? "" : " ") + temp);  
                    }
                }
            }
        }
        return dp[n];
    }

    
};
