#include<bits/stdc++.h>
using namespace std;

int parkingSpace(int n, vector<vector<int>>& nums){
    int j=1;
    // sort(nums.begin() , nums.end());
    // int count=0;
    // for(int i=1 ; i<n ; i++){
    //     if( nums[i][0]>=nums[i-1][j] && nums[i][1]<=nums[i-1][1]) continue;
    //     if( nums[i][0]<=nums[i-1][j] && nums[i][1]>=nums[i-1][1]) count++;
    //     if( nums[i][0]<=nums[i-1][j] && nums[i][1]<=nums[i-1][1]) continue;
    //     if( nums[i][0]>=nums[i-1][j] && nums[i][1]<=nums[i-1][1]) continue;
    // }
    map<int,int>mp;
    for(int i=0 ; i<n ; i++){
        mp[nums[i][0]]++;
        mp[nums[i][1]]--;
    }
    int ans=0;
    int count=0;
    for(auto it: mp){
        count += it.second;
        ans = max(ans,count);
    }
    return ans;

}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>times(n);
    for (int i = 0; i < n; i++)
    {
        int a, d;
        cin>>a>>d;
        times[i].push_back(a);
        times[i].push_back(d);
    }
    int ans = parkingSpace(n, times);
    cout<<ans;
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