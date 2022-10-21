#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > direction = { { 1, 0 }, { 0, -1 }, { -1, 0 }, { 0, 1 } };

int zombies(int n, int m, vector<vector<int>> &arr){
    vector<vector<bool>> visited(n,vector<bool>(m,0));
    queue<pair<pair<int, int>, int> > q; 
      int uninfected_count=0;
      int time = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 2) {
                q.push({ { i, j }, 0 });
                visited[i][j] =  1;
            }
              if(arr[i][j] == 1){
                uninfected_count++;
            }
        }
    }
    while (!q.empty()) {
        pair<pair<int, int>, int> current
            = q.front();
        time = current.second;
        q.pop();
        for (auto it : direction) {
            int i = current.first.first
                    + it.first;
            int j = current.first.second + it.second;
            if (i < 0 || j < 0 || i >= n
                || j >= m || arr[i][j] != 1
                || visited[i][j] != 0) {
                continue;
            }
            q.push({ { i, j }, time + 1 });
            visited[i][j] = 1;
              uninfected_count--;
        }
    }
    if (uninfected_count != 0)
        return -1;
    return time;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> v(n, vector<int>(m));
        int i, j;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>v[i][j];
            }
        }
        cout<<zombies(n, m, v)<<endl;
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