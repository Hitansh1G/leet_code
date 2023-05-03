#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
    
    int helper(vector<int>& nums,int target,int n,int index,int sum){
        if(index==n){
            if(sum==target){
                return 1;
            }
            return 0;
        }
        if(dp[index][sum+1000]!=-1){
            return dp[index][sum+1000];
        }
        return dp[index][sum+1000]= helper(nums,target,n,index+1,sum+nums[index]) + helper(nums,target,n,index+1,sum);
    }
int targetSum(vector<int>& nums, int target)
{
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
    }
    if((sum-target)%2!=0){
        return 0;
    }
    int newTarget = (sum-target)/2;
    dp.resize(22,vector<int>(2010,-1));
    return helper(nums,newTarget,n,0,0);
}


int main()
{
    int n,target;
    cin>>n>>target;
    vector<int>nums(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<targetSum(nums,target);

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