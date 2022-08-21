class Solution {
    
    int startrow = 0, startcol = 0, count = 0, ans  = 0;
    void dfs(vector<vector<int>>& grid, int i , int j , int cellvisited){
        if(i<0 || j<0 || i>= grid.size() || j>= grid[0].size() || grid[i][j] == -1 )
            return ;
        if(grid[i][j] == 2 ){
            if(cellvisited == count)
                ans++;
            return ;
        }
        grid[i][j] = -1;
        dfs(grid, i+1 , j , cellvisited+1);
        dfs(grid, i-1 , j , cellvisited+1);
        dfs(grid, i , j+1 , cellvisited+1);
        dfs(grid, i , j-1 , cellvisited+1);
        grid[i][j] = 0;
    }
  
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        for(int i = 0 ; i<grid.size() ; i++){
            for(int j = 0 ; j<grid[0].size() ; j++){
                if(grid[i][j] == 1)
                    startrow = i, startcol = j;
                else if(grid[i][j] == 0)
                    count++;
            }
        }
        count++;
        int cellvisited = 0;
        dfs(grid, startrow, startcol, cellvisited);
        return ans;
    }
};