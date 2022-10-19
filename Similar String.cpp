#include <bits/stdc++.h>
using namespace std;

string similarString(string s1,string s2,int n,int m ,int k){
    // if(n==0 || m==0){
    //     cout<<"Yes";
    // }
    unordered_map<char,int>one;
    unordered_map<char,int>sec;
    // if(n!=m){
    //     return "NO";
    // }
    for(int i=0 ; i<n ; i++){
        one[s1[i]]++;
        // sec[s2[i]]++;
    }
    for(int i=0 ; i<m ; i++){
        // one[s1[i]]++;
        sec[s2[i]]++;
    }
 
    // bool flag=true;

    for(char c='a' ; c<='z' ; c++){
        if(abs(one[c]-sec[c])>k)return "No";
    }
    // bool po = false;
    // for(auto it:one){
    //     auto temp1=it.first;
    //     auto temp2=it.second;

    //     if(sec.find(temp1)!=sec.end()){
    //         int mob=one[temp1];
    //         int bom=sec[temp1];

    //         int diff=abs(mob-bom);
    //         if(diff>k){
    //             return "No";
    //             // po = false;
    //         }
    //     }
    //     // else continue;
    // }
    // for(auto it:sec){
    //     auto temp1=it.first;
    //     auto temp2=it.second;

    //     if(one.find(temp1)!=one.end()){
    //         int mob=sec[temp1];
    //         int bom=one[temp1];

    //         int diff=abs(mob-bom);
    //         if(diff>k){
    //             return "No";
    //             // po = false;
    //         }
    //     }
    //     // else continue;
    // }
    return "Yes";
}


int main(){
    int testcases;
    cin>>testcases;
    while(testcases--){
        int n,m,k;
        cin>>n>>m>>k;
        string s1,s2;
        cin>>s1;
        cin>>s2;
        string result = similarString(s1,s2,n,m,k);
        cout << result << endl;
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