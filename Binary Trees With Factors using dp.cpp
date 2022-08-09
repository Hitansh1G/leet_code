class Solution {
public:
    int mod = 1e9 + 7;
    unordered_map<int, int> dp;
    
    int findSubTree(vector<int>& arr,unordered_map<int, int>& hash, int prod){
        if(dp.find(prod) != dp.end())
            return dp[prod];
        
        long long cnt = 1;
        
        for(int &a: arr){
            if( (prod % a) == 0  and hash[prod / a] != 0){
                cnt = (cnt + (findSubTree(arr, hash, a) % mod * 1LL * findSubTree(arr, hash, prod / a) % mod) % mod) % mod;
            }
        }
        
        return dp[prod] = (int)cnt;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        long long ans = 0;
        unordered_map<int, int> hash;
        
        for(int &a: arr)
            hash[a]++;
        
        for(int &a: arr)
            ans = (ans + findSubTree(arr, hash, a) % mod) % mod;     
        
        return (int)ans;
    }
};