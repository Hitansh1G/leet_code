class Solution {
public:
    vector<vector<vector<int>>> dp;

    int fun(int ai,int aj,int bi,vector<vector<int>>& mat,int n){

        int bj = ai+aj-bi;

        if(ai >= n || aj >= n || bi >= n || bj >= n || mat[ai][aj] == -1 || mat[bi][bj] == -1)
            return INT_MIN;
        else if(ai == n-1 && aj == n-1)
            return mat[ai][aj];
        if(dp[ai][aj][bi] != -1)return dp[ai][aj][bi];


        int ans = INT_MIN;

        int x = mat[ai][aj] , y = mat[bi][bj];
        mat[ai][aj] = mat[bi][bj] = 0;

        int p = fun(ai+1, aj, bi+1, mat, n);
        int q = fun(ai+1, aj, bi, mat, n);
        int r = fun(ai, aj+1, bi+1, mat, n);
        int s = fun(ai, aj+1, bi, mat, n);

        ans = max({p,q,r,s});

        mat[ai][aj] = x;  mat[bi][bj] = y;
        return dp[ai][aj][bi] = (ans == INT_MIN?ans : ans+(ai == bi? x : x+y));  
    }


    int cherryPickup(vector<vector<int>>& mat) {

        int n = mat.size();
        dp = vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1)));

        int ans = fun(0,0,0,mat,n);
        return ans == INT_MIN? 0 : ans;
    }
};