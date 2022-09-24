#include<bits/stdc++.h>
using namespace std;

int rottingOranges(vector<vector<int>>& grid) {
    queue<pair<pair<int,int>, int>>q;
    if(grid.size()==0) return 0;
    for(int i=0 ; i<grid.size() ; i++)
        for(int j=0 ; j<grid[i].size() ; j++)
            if(grid[i][j]==2)
                q.push({{i,j},0});
            int maxi = 0;
            while(!q.empty()){
                pair<pair<int,int>,int>t = q.front();
                q.pop();
                maxi = max(maxi,t.second);
                int row = t.first.first;
                int col = t.first.second;
                if(row-1>=0 && grid[row-1][col]==1){
                    grid[row-1][col]=2;
                    q.push({{row-1,col},t.second+1});
                }
                if(col-1>=0 && grid[row][col-1]==1){
                    grid[row][col-1]=2;
                    q.push({{row,col-1},t.second+1});
                }
                if(row+1<grid.size() && grid[row+1][col]==1){
                    grid[row+1][col]=2;
                    q.push({{row+1,col},t.second+1});
                }
                if(col+1<grid[0].size() && grid[row][col+1]==1){
                    grid[row][col+1]=2;
                    q.push({{row,col+1},t.second+1});
                }
            }
            for(int i=0 ; i<grid.size() ; i++)
                for(int j=0 ; j<grid[i].size() ; j++)
                    if(grid[i][j]==1) return -1;
                    return maxi;
            
        
}

int main() {
    int n, m, t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for ( int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        cout << rottingOranges(grid) << endl;
    }
}

/* 
Crio Methodology

Milestone 1: Understand the problem clearly
1. Ask questions & clarify the problem statement clearly.
2. Take an example or two to confirm your understanding of the input/output & extend it to test cases
Milestone 2: Finalize approach & execution plan
1. Understand what type of problem you are solving.
     a. Obvious logic, tests ability to convert logic to code
     b. Figuring out logic
     c. Knowledge of specific domain or concepts
     d. Knowledge of specific algorithm
     e. Mapping real world into abstract concepts/data structures
2. Brainstorm multiple ways to solve the problem and pick one
3. Get to a point where you can explain your approach to a 10 year old
4. Take a stab at the high-level logic & write it down.
5. Try to offload processing to functions & keeping your main code small.
Milestone 3: Code by expanding your pseudocode
1. Make sure you name the variables, functions clearly.
2. Avoid constants in your code unless necessary; go for generic functions, you can use examples for your thinking though.
3. Use libraries as much as possible
Milestone 4: Prove to the interviewer that your code works with unit tests
1. Make sure you check boundary conditions
2. Time & storage complexity
3. Suggest optimizations if applicable
*/