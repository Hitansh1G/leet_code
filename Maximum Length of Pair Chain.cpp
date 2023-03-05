
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        // int count=0;
        // int ans=0;
        // for(int i=0 ; i<n-1 ; i++){
        //     int a=pairs[i][0];
        //     int b=pairs[i][1];
        //     int c=pairs[i+1][0];
        //     int d=pairs[i+1][1];
        //     if(a<=b && b<=c && c<=d){
                
        //         count++;
        //         cout<<count<<endl;
        //         ans=max(ans,count);
        //         cout<<ans<<endl;
        //     }
        //     else{
        //         count=0;
        //     }
        // }
        // return ans;
        sort(pairs.begin(), pairs.end());
        if (n==1) return 1;
        vector<int> dp(n, 1);
        for (int i=1; i<n; i++){
            for (int j=0; j<i; j++){
                if ( pairs[j][1]<pairs[i][0] ){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};