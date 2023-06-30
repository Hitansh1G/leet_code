class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count=0;
        vector<pair<int,int>>v;
        int n=grid.size();
        int m=grid[0].size();


        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 1){
                    v.push_back({i,j});
                }
            }
        }

        count = 4*(v.size());

        for(int i=0 ; i<v.size() ; i++){
            int x =v[i].first;
            int y = v[i].second;

            if(x!=0 && grid[x-1][y] == 1) 
                count--; 
            if(x!= grid.size()-1 && grid[x+1][y] == 1) 
                count--; 
            if(y!=0 && grid[x][y-1] == 1) 
                count--; 
            if(y!=grid[0].size()-1 && grid[x][y+1] == 1) 
                count--;         
        }
        return count;
    }
};