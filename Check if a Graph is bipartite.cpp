#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100005];
int color[100005];
int dfs(int u, int c){
    color[u]=c;
    for(int i=0 ; i<adj[u].size() ; i++){
        if(!color[adj[u][i]]){
            if(!dfs(adj[u][i],3-c)) return 0;
        }
        else if(color[adj[u][i]] != 3-c)return 0;
    }
    return 1;
}
string possibleBipartition(int N, vector<vector<int>>& edges) {
    for(int i=0 ; i<=N ; i++){
        adj[i].clear();
        color[i]=0;
    }
    for(int i=0 ; i<edges.size() ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1 ; i<=N ; i++)
        if(!color[i]){
            if(!dfs(i,1))return "Not Possible";

        }
        return "Possible";

    
}

int main() {
    int n, e, tests;
    cin >> tests;
    while (tests--) {
        cin >> n >> e;
        vector< vector<int> > edges;
        for (int i = 0; i < e; i++) {
            int x, y;
            cin >> x >> y;
            edges.push_back({x, y});
        }
        string answer =  possibleBipartition(n, edges) ;
        cout << answer << endl;
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