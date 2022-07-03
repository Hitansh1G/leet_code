class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int k = m*n;
        vector<int> ans(k);
        int x=0;
        int r1=0,r2=n-1,c1=0,c2=m-1;
        while(x<k){
            if(c1<=c2){
                for(int i=c1;i<=c2;i++){
                    ans[x] = mat[r1][i];
                    cout<<ans[x]<<" ";
                    x++;
                    if(x>=k) break;
                }
                if(x>=k) break;
            }
            
            if(r1+1<n && r1<r2){
                for(int i=r1+1;i<=r2;i++){
                    ans[x] = mat[i][c2];
                    cout<<ans[x]<<" ";
                    x++;
                    if(x>=k) break;
                }
                if(x>=k) break;
            }
            
            if(c2-1>=0 && c2>c1){
                for(int i=c2-1;i>=c1;i--){
                    ans[x] = mat[r2][i];
                    cout<<ans[x]<<" ";
                    x++;
                    if(x>=k) break;
                }
                if(x>=k) break;
            }
            if(r2-1>=0 && r2>r1){
                for(int i=r2-1;i>r1;i--){
                    ans[x] = mat[i][c1];
                    cout<<ans[x]<<" ";
                    x++;
                    if(x>=k) break;
                }
                if(x>=k) break;
            }
            r1++; r2--;
            c1++; c2--;
        }
        return ans;
    }
};