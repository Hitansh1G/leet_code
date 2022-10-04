#include <bits/stdc++.h>
using namespace std;
bool helper(int n, vector<int>a , int t, vector<vector<bool> >dp){
    for(int i=0 ; i<n+1 ; i++){
        dp[i][0]=true;
    }
    for (int i = 1; i <= t; i++)
        dp[0][i] = false;
    
    for(int i=1 ; i<n+1 ; i++){
        for(int j=1 ; j<t+1 ; j++){
            if(a[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]];
            }
        }
    }
    return dp[n][t];
}
bool subsetSum(vector<int> a,int t){
    int n=a.size();
    vector<vector<bool> >dp(n+1,vector<bool>(t+1));
    return helper(n,a,t,dp);
}


int main(){
    int n,t;
    cin>>n>>t;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<subsetSum(a,t);
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