class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        int dp[n]; memset(dp,0,sizeof(dp));
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++) v[i].first=arr[i],v[i].second=i;
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        for(int i=0;i<n;i++){
            int id=v[i].second;
            for(int j=id+1;j<min(id+d+1,n);j++)
                if(arr[j]<arr[id])
                    dp[j]=max(dp[j],dp[id]+1);
                else break;
            for(int j=id-1;j>=max(id-d,0);j--)
                if(arr[j]<arr[id])
                    dp[j]=max(dp[j],dp[id]+1);
                else break;
        }
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,dp[i]);
        return ans+1;
    }
};

