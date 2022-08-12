#include <bits/stdc++.h>
using namespace std;

vector<int> countDistinctElements(int n, int b, vector<int> a){
    if(b>n){
        return {};
    }
    vector<int>dis;
    unordered_map<int,int>mp;
    for(int i=0 ; i<b ; i++){
        mp[a[i]]++;
    }
    dis.push_back(mp.size());
    for(int i=1 ; i<=n-b ; i++){
        mp[a[i-1]]--;
        if(mp[a[i-1]]==0){
            mp.erase(a[i-1]);
        }
        mp[a[i+b-1]]++;

        int distinct = mp.size();
        dis.push_back(distinct);
    }
    return dis;
}


int main(){
    int n, b;
    cin>> n >> b;
    vector<int> a(n);
    for(auto &i: a)
        cin>> i;
    vector<int> result = countDistinctElements(n, b, a);
    assert( result.size() == max(0,n - b + 1) );
    for(auto &i: result){
        cout << i << " " ;
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