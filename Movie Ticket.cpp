#include <bits/stdc++.h>
using namespace std;

int movieTicket(int n,int arr[],int amount){
    // int dp[n+1][k+1];
    // int ans=INT_MAX;
    // for(int i=0 ; i<n+1 ; i++){
    //     for(int j=0 ; j<n+1 ; j++){
    //         if(n==0 || j==0 ){
    //             dp[i][j]=0;
    //         }
    //         else if(arr[i-1]==arr[j-1]){
    //             dp[i][j]=1+dp[i-1][j-1];
    //         }
    //         else{
    //             dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
    //         }
    //     }
    // }
    // return dp[n][n];
    int dp[n+1][amount+1];
    for(int i=0; i<amount+1; i++) 
        dp[0][i] = INT_MAX-1;
    for(int j=1; j<n+1; j++) 
        dp[j][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=amount;j++){
            int take=INT_MAX;
            if(j>=arr[i-1]){
                take = 1+dp[i][j-arr[i-1]];
            }
            int skip = dp[i-1][j];

            dp[i][j]=min({take,skip});
        }
    }
    int x=dp[n][amount];
    if(x==INT_MAX-1)return -1;
    return x;
}


int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    int k;
    cin>>k;
    cout<<movieTicket(n,array,k);
    

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