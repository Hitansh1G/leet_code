#include <bits/stdc++.h>
using namespace std;
vector<int>adj[1005];
int visited[1005];
int dfs(int curr , int par){
    visited[curr]=1;
    for(int i=0 ; i<adj[curr].size() ; i++){
        if(!visited[adj[curr][i]]){
            if(dfs(adj[curr][i],curr)) return 1;
        }
        else if(adj[curr][i]!=par){
            return 1;
        }
    }
    return 0;
}
string detectCycle(int nodes, vector<vector<int>> &edgelist)
{
    //convert to adjancy list
    
    for(int i=0 ; i<=nodes ; i++){
        visited[i]=0;
        adj[i].clear();
    }
    for(int i=0 ; i<edgelist.size() ; i++){
        vector<int>u = edgelist[i];
        adj[u[0]].push_back(u[1]);
        adj[u[1]].push_back(u[0]);
    }
    // if(dfs(1,0))return "Yes";
    // else return "No";
    for(int i=0 ; i<=nodes ; i++){
        if(!visited[i]){
            if(dfs(i,0))return "Yes";
        }
    }
    return "No";
}

int main()
{
    int tests;
    cin>>tests;
    while (tests--)
    {
        int nodes;
        cin>>nodes;
        int edges;
        cin>>edges;
        int vertex1,vertex2;
        vector<vector<int > > edgelist;
        for(int i=0;i<edges;i++)
        {
            cin>>vertex1>>vertex2;
            vector<int > temp = {vertex1,vertex2};
            edgelist.push_back(temp);
        }
        string answer = detectCycle(nodes, edgelist);
        cout<<answer<<"\n";
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
3. Suggest optimizations if applicabl
*/