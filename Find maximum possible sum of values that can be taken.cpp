#include <bits/stdc++.h>
using namespace std;
// int dp[105][]
long long int maxValue(int W,vector<int> &wt, vector<int> &val){
    int n=val.size();
    int i, w;
    vector<vector<long long int>> dp(n + 1, vector<long long int>(W + 1));
    for(i = 0; i <= n; i++){
        for(w = 0; w <= W; w++){
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}


int32_t main(){
    int N,W;
    cin>>N>>W;
    vector<int>w(N),v(N);
    for(int i=0;i<N;i++){
        cin>>w[i];
    }
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    cout<<maxValue(W,w,v)<<"\n";
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