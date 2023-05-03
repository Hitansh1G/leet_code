#include <bits/stdc++.h>
using namespace std;

void helper(vector<int>&candidates, int target, vector<vector<int>>&res, vector<int>&r, int i){
    if(target==0){
        res.push_back(r);
    }
    while(i<candidates.size() && target-candidates[i]>=0){
        r.push_back(candidates[i]);
        helper(candidates,target-candidates[i],res,r,i);
        i++;
        r.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    //sort
    //remove all dublicates 
    //if sum==0 then add that vector into the final ans
    //if sum < 0 then ignore 
    //if sum>0 insert the present index in the current vector and call the functoin 
    sort(candidates.begin(),candidates.end()); 
    candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
        
    vector<int> r;
    vector<vector<int> > res;
    
    helper(candidates,target,res,r,0);
    
    return res;

}


int main()
{
    int n,target;
    cin>>n>>target;
    vector<int>candidates(n,0);
    for(int i=0;i<n;i++)cin>>candidates[i];

    vector<vector<int>>vec=combinationSum(candidates,target);
    if(vec.size()==0)
    {
        cout<<"NA";
    }
    for(auto x:vec)
    {
       for(auto y:x)cout<<y<<" ";
       cout<<endl;
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