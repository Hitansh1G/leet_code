#include <bits/stdc++.h>
using namespace std;

bool conditionFail(pair<int, int > &pos, vector<vector<int>> &matrix, int &n){
    int x = pos.first, y = pos.second;
    if(x >= n || x < 0 || y >= n || y < 0)
        return true;
    if (matrix[x][y] != 0)
        return true;
    return false;
}  

vector<vector<int > > spiralMatrixII(int n){
    vector<vector<int>>ans(n,vector<int>(n));
        int k=1;
        int l = 0, t = 0, r = n-1, b = n-1;
        while(k<=n*n){
            for(int i=l; i<=r; i++) ans[t][i] = k++;
            t++;
            for(int i=t; i<=b; i++) ans[i][r] = k++;
            r--;
            for(int i=r; i>=l; i--) ans[b][i] = k++;
            b--;
            for(int i=b; i>=t; i--) ans[i][l] = k++;
            l++;
        }
        return ans;
}


int main(){
    int n;
    cin>>n;
    vector<vector<int> > result = spiralMatrixII(n);
    for(auto &row: result){
        for(auto &element: row){
            cout<<element<<" ";
        }
        cout<<"\n";
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