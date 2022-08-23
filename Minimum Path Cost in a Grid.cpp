class Solution {
public:
    int t[51][51];
    int util(vector<vector<int>>& grid, vector<vector<int>>& moveCost,int i,int j, int n, int m){
        if(i==n-1)
            return grid[i][j];
        if(t[i][j]!=-1)
            return t[i][j];
        int ans=INT_MAX;
        for(int k=0;k<m;k++){
            ans=min(ans, grid[i][j] + 
                    moveCost[grid[i][j]][k]+util(grid,moveCost,i+1,k,n,m));
        }
        
        return t[i][j]=ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n=grid.size();
        int m=grid[0].size();
        memset(t,-1,sizeof(t));
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            ans= min (  ans , util(grid,moveCost,0,i,n,m) );
        }
        
        return ans;
    }
};