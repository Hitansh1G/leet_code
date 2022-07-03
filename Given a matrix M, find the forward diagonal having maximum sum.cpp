#include <bits/stdc++.h>
using namespace std;

int largestForwardDiagonal(const vector<vector<int>> & vec){
    vector<vector<int>>result=vec;
    int n=vec.size();
    int m=vec[0].size();
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(i==0 || j==0)
                result[i][j]=vec[i][j];
            else result[i][j]=vec[i][j]+result[i-1][j-1];
        }
    }
    int ans=-1;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(i==n-1 || j==m-1){
                ans = max(ans,result[i][j]);
            }
        }
    }
    return ans;
}


int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>M(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>M[i][j];
        }
    }
    int result = largestForwardDiagonal(M);
    cout<<result;
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