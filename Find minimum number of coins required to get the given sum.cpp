#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int>& coins, long long V){
    // long long n=coins.size();
//     long long dp[n+1][s+1];
// // cout<<"yes"<<endl;
//     for(long long i=0 ; i<n+1 ; i++){
//         dp[i][0]=0;
        
//         // dp[0][i]=INT_MAX;
//     }
//     for(long long i=0 ; i<s+1 ; i++){
//         // dp[i][0]=0;
//         dp[0][i]=10000;
//     }

//     for(long long i=1 ; i<n+1 ; i++){
//         for(long long j=1 ; j<s+1 ; j++){
//             if(coins[i-1]<=j){
//                 dp[i][j] = min(1 + dp[i][j-coins[i-1]] , dp[i-1][j]);
//                 // cout<<dp[i][j]<<" "<<i<<" "<<j<<endl;
//             }
//             else{
//                 dp[i][j]=dp[i-1][j];
//                 // cout<<dp[i][j]<<" "<<i<<" "<<j<<endl;
//             }
//         }
//     }
//     if(dp[n][s]==INT_MAX)return -1;
//     return dp[n][s];
    int m = coins.size();
    int table[V + 1];
    table[0] = 0;
    for (int i = 1; i <= V; i++)
        table[i] = INT_MAX;
    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < m; j++)
            if (coins[j] <= i) {
                int sub_res = table[i - coins[j]];
                if (sub_res != INT_MAX
                    && sub_res + 1 < table[i])
                    table[i] = sub_res + 1;
            }
    }
 
    if (table[V] == INT_MAX)
        return -1;
 
    return table[V];
}


int main(){
    int n,amount;
    cin>>n>>amount;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    cout<<minCoins(coins,amount)<<"\n";
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