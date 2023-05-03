class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
       int n=matrix.size();
    int m=matrix[0].size();
        map<int,int>mp;
        for(int i=0; i<n; i++){
            for(int j=1; j<m; j++){
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        int ans=0;
        for(int c1=0; c1<m; c1++){
            for(int c2=c1; c2<m; c2++){
                mp.clear();
                mp[0]=1;
                int sum=0;
                for(int i=0; i<n; i++){
                    sum=sum+matrix[i][c2]-(c1>0?matrix[i][c1-1]: 0);
                    if(mp.find(sum-target)!=mp.end()){
                        ans=ans+mp[sum-target];
                    }
                    mp[sum]++;
                }
            }
        }
        return ans;
    }
};