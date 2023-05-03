class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n));
        int k=1;
        int l = 0, t = 0, r = n-1, b = n-1;
        while(k<=n*n){
            for(int i=l; i<=r; i++) ans[t][i] = k++;
            t++;
            for(int i=t; i<=b; i++) ans[i][r] = k++;
            r--;
            for(int i=r; i>=l; i--) ans[b][i] = k++;
            b--;
            for(int i=b; i>=t; i--) ans[i][l] = k++;
            l++;
        }
        return ans;
    }
};