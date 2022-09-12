#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<int,int> &a,const pair<int,int> &b){
    //to sort in decreasing order of first and inc order of second
    // return a.second>b.second;
    if(a.first!=b.first){
        return a.first>b.first;
    }
    else return a.second<b.second;
}
int jobSequencing(int n, vector<int>&deadlines, vector<int>&profits){
    vector<pair<int,int>>sol;
    for(int i=0 ; i<n ; i++){
        sol.push_back({profits[i],deadlines[i]});
    }
    sort(sol.begin(),sol.end(),cmp);
    // int temp = sol[n-1].first;
    // int sum=0;
    // sort(profits.begin(), profits.end(), greater<int>());
    // for(auto p : sol){
    //     cout<<p.first<<" "<<p.second<<endl;
    // }
    // return 0;
    int maxdeadline = *max_element(deadlines.begin(),deadlines.end());
    vector<int>arr(maxdeadline+1,-1);
    int sum=0;
    for(int i=0 ; i<n ; i++){
        for(int j=sol[i].second ; j>0 ; j--){
            if(arr[j]==-1){
                sum+= sol[i].first;
                arr[j]=i;
                break;
            }

        }
    }
    // for(int i=0 ; i<maxdeadline+1 ; i++){
    //     cout<<arr[i]<<" ";
    // }
    return sum;


}

int main(){
    int N;
    cin>>N;
    vector<int>deadlines(N), profits(N);
    for(int i=0;i<N;i++){
        cin>>deadlines[i];
    }
    for(int i=0;i<N;i++){
        cin>>profits[i];
    }
    cout<<jobSequencing(N, deadlines, profits);
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