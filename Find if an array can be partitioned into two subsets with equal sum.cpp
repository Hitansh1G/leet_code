#include <bits/stdc++.h>
using namespace std;
// bool helper(int n, vector<int>&nums, int t, bool *dp[]){
    // for(int i=0 ; i<n+1 ; i++){
    //     dp[i][0]=true;
    // }
    // for(int i=1 ; i<t+1 ; t++){
    //     dp[0][i]=false;
    // }
    // for(int i=0 ; i<n+1 ; i++){
    //     for(int j=0 ; j<t+1 ; j++){
    //         if(i==0) dp[i][j]=false;
    //         if(j==0) dp[i][j]=true;
    //         else if(nums[i-1]<=j){
    //             dp[i][j] = dp[i-1][j] || (dp[i][j]-nums[i-1]);
    //         }
    //         else{
    //             dp[i][j]=dp[i-1][j];
    //         }
    //     }
    // }
    // return dp[n][t];
    // int i,j;
    // for (i = 0; i <= n; i++)
    //     dp[0][i] = true;
    // for (i = 1; i <=t ; i++)
    //     dp[i][0] = false;
    // for (i = 1; i <= t ; i++) {
    //     for (j = 1; j <= n; j++) {
    //         dp[i][j] = dp[i][j - 1];
    //         if (i >= nums[j - 1])
    //             dp[i][j] = dp[i][j] || dp[i - nums[j - 1]][j - 1];
    //     }
    // }
    // return dp[n][t];
// }
bool equalSumPartition(vector<int>& arr){

    int n=arr.size();
    // int sum=0;
    // for(int i=0 ; i<n ; i++){
    //     sum+=nums[i];
    // }
    // // vector<vector<bool>>dp(n+1,vector<bool>((sum/2)+1));
    // bool dp [sum/2 + 1][n + 1];
    // if(sum%2==1){
    //     return false;
    // }
    
    // else{
    //     int t=sum/2;
    //     int i,j;
    //     for (i = 0; i <= n; i++)
    //         dp[0][i] = true;
    //     for (i = 1; i <=t ; i++)
    //         dp[i][0] = false;
    //     for (i = 1; i <= t ; i++) {
    //         for (j = 1; j <= n; j++) {
    //             dp[i][j] = dp[i][j - 1];
    //             if (i >= nums[j - 1])
    //                 dp[i][j] = dp[i][j] || dp[i - nums[j - 1]][j - 1];
    //         }
    //     }
    //     return dp[n][t];
    // }
    // return helper(n,nums,sum/2,dp);
    int sum = 0;
    int i, j;
    for (i = 0; i < n; i++)
        sum += arr[i];
 
    if (sum % 2 != 0)
        return false;
 
    bool part[sum / 2 + 1][n + 1];
    for (i = 0; i <= n; i++)
        part[0][i] = true;
    for (i = 1; i <= sum / 2; i++)
        part[i][0] = false;
    for (i = 1; i <= sum / 2; i++) {
        for (j = 1; j <= n; j++) {
            part[i][j] = part[i][j - 1];
            if (i >= arr[j - 1])
                part[i][j] = part[i][j]
                             || part[i - arr[j - 1]][j - 1];
        }
    }
 
    return part[sum / 2][n];
}


int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<equalSumPartition(nums);
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