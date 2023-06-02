class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>ans(n,vector<int>(m,0));
        
        unordered_set<int>st1;
        unordered_set<int>st2;
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                
                int a=i+1;
                int b=j+1;
                while(a<n && b<m){
                    st1.insert(grid[a][b]);
                    a++;
                    b++;
                }
                a=i-1;
                b=j-1;
                while(a>=0 && b>=0){
                    st2.insert(grid[a][b]);
                    a--;
                    b--;
                }
                
                ans[i][j]=abs((int)st1.size()-(int)st2.size());
                st1.clear();
                st2.clear();
            }
        }
        return ans;
    }
};class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>ans(n,vector<int>(m,0));
        
        unordered_set<int>st1;
        unordered_set<int>st2;
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                
                int a=i+1;
                int b=j+1;
                while(a<n && b<m){
                    st1.insert(grid[a][b]);
                    a++;
                    b++;
                }
                a=i-1;
                b=j-1;
                while(a>=0 && b>=0){
                    st2.insert(grid[a][b]);
                    a--;
                    b--;
                }
                
                ans[i][j]=abs((int)st1.size()-(int)st2.size());
                st1.clear();
                st2.clear();
            }
        }
        return ans;
    }
};