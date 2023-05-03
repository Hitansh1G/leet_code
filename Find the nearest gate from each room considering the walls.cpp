#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> wallsAndGates(vector<vector<int>> &rooms)
{
    vector<vector<int>>ans;
    const int row = rooms.size();
    if (0 == row) return {};
    const int col = rooms[0].size();
    queue<pair<int, int>> canReach;  
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; 
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(0 == rooms[i][j])
                canReach.emplace(i, j);
        }
    }
    while(!canReach.empty()){
        int r = canReach.front().first, c = canReach.front().second;
        canReach.pop();
        for (auto dir : dirs) {
            int x = r + dir.first,  y = c + dir.second;
            if (x < 0 || y < 0 || x >= row || y >= col || rooms[x][y] <= rooms[r][c]+1) continue;
            rooms[x][y] = rooms[r][c] + 1;
            canReach.emplace(x, y);
        }
    }
    return rooms;
}

int main()
{
    vector<vector<int>> grid;
    int n, m;
    cin >> n >> m;

    grid.resize(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> b(m, 0);
        for (int j = 0; j < m; j++)
        {
            cin >> b[j];
        }
        grid[i] = b;
    }
    vector<vector<int>> ans = wallsAndGates(grid);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
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