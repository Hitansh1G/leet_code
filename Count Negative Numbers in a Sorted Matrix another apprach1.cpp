class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int i=0,j=m-1;
        int ans=0;
        while(i>=0 && j>=0 && i<n && j<m){
            if(grid[i][j]<0){
                ans+=n-i;
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};