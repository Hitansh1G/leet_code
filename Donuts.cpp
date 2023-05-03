#include <bits/stdc++.h>
using namespace std;

int donuts(int n, int b, vector<int> arr){
    // int sum=0;
    // for(int i=0 ; i<b ; i++){
    //     sum += arr[i];
    // }
    // int old=0;
    // int neww=0;
    // int maxi=0;
    // for(int i=1; i<b ; i++){
    //     // int temp = sum - arr[b-i] + arr[n-i];
    //     old += arr[b-i];
    //     neww += arr[n-i];
    //     int temp = sum - old + neww;
    //     sum = max( sum , temp );
    //     // cout<< sum <<" "<< temp <<" "<< endl;
    // }
    // return maxi;
    int sum=0;
    for(int i=0 ; i<b ; i++){
        sum += arr[i];
    }
    int mx = sum;
    int a = b-1;
    int c = n-1;
    while(b--){
        sum = sum-arr[a];
        sum = sum +arr[c];
        c--;
        a--;
        mx = max(mx,sum);
    }
    return mx;
}


int main(){
    int n, b;
    cin>>n>>b;
    vector<int > A(n);
    for(auto &i: A){
        cin>>i;
    }
    int result = donuts(n, b, A);
    cout<< result << "\n";
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