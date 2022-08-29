class Solution {
public:
    int countSubIslands(vector<vector<int>>& g, vector<vector<int>>& grid) {
        int m=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0)
                    continue;
                int c=0,k=0;
                if(grid[i][j]==1){
                    queue<vector<int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        c++;
                        vector<int> a;
                        a=q.front();
                        q.pop();
                        if(g[a[0]][a[1]]==1)
                            k++;
                        grid[a[0]][a[1]]=2;
                        if(a[0]+1<grid.size() &&  grid[a[0]+1][a[1]]==1){
                            q.push({a[0]+1,a[1]});
                            grid[a[0]+1][a[1]]=0;
                        }
                        if(a[1]+1<grid[0].size() && grid[a[0]][a[1]+1]==1){
                            q.push({a[0],a[1]+1});
                            grid[a[0]][a[1]+1]=0;
                        }
                        if(a[0]-1>=0 && grid[a[0]-1][a[1]]==1){
                            q.push({a[0]-1,a[1]});
                            grid[a[0]-1][a[1]]=0;
                        }
                        if(a[1]-1>=0 && grid[a[0]][a[1]-1]==1){
                            q.push({a[0],a[1]-1});
                            grid[a[0]][a[1]-1]=0;
                        }
                    }
                    if(k==c)
                        m++;
                }
            }
        }
        return m;
    }
};