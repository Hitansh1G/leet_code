class Solution {   
public:
    int m, n;
    int mx[2];
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size(), n = land[0].size();
        vector<vector<int>> res;
        for(int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++) 
                if(land[i][j] == 1) {
                    mx[0] = i,mx[1] = j;
                    dfs(i,j,land);
                    res.push_back({i,j,mx[0],mx[1]});
                }
        
        return res;
    }
    
    void dfs(int i,int j, vector<vector<int>> &land) {
        if(i < 0 || j < 0 || i == m || j == n || land[i][j] == 0)
            return;
        mx[0] = max(mx[0],i);
        mx[1] = max(mx[1],j);
        land[i][j] = 0;
        dfs(i+1,j,land);
        dfs(i-1,j,land);
        dfs(i,j+1,land);
        dfs(i,j-1,land);
    }
};