#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalOrdering(int n,int e, vector<vector<int>>& edges){
    vector<int>in(n+1);
    vector<vector<int>>adj(n+1);
    for(auto && edge: edges){
        adj[edge[0]].push_back(edge[1]);
        in[edge[1]]++;
    }
    queue<int>q;
    vector<int>ans;
    for(int node=1 ; node<=n ; node++){
        if(in[node]==0){
            q.push(node);
        }
    }
    while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for(auto &&child : adj[node]){
            in[child]--;
            if(in[child]==0){
                q.push(child);
            }
        }
    }
    return ans;
}

int main(){
    
    int n,e;
    cin>>n>>e;
    vector<vector<int>>edges(e);
    for (int i = 0; i < e; i++)
    {
        int u,v;
        cin>>u>>v;
        edges[i].push_back(u);
        edges[i].push_back(v);
    }
    vector<int>ans = topologicalOrdering(n,e,edges);
    for (auto &&i : ans)
    {
        cout<<i<<" ";
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