class Solution {
public:
    void solve(int ind,int &ans,int len,unordered_map<int,int> &cnt,vector<vector<int>> &requests){
        if(ind>=requests.size()){
            for(auto it:cnt){
                if(it.second!=0){
                    return;
                }
            }
            ans=max(ans,len);
            return;
        }
        // not taking the current request element
        solve(ind+1,ans,len,cnt,requests);
        // taking the current element and adding it to cnt map
        cnt[requests[ind][0]]--;
        cnt[requests[ind][1]]++;
        solve(ind+1,ans,len+1,cnt,requests);
        cnt[requests[ind][0]]++;
        cnt[requests[ind][1]]--;
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        unordered_map<int,int>cnt;
        int ans=0;
        solve(0,ans,0,cnt,requests);
        return ans;
    }
};