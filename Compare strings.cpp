#include <bits/stdc++.h>
using namespace std;
string removeBackspaces(string& s){
    int n = s.size();
    int idx = 0;
 
    for (int i = 0; i < n; i++) {
        if (s[i] != '#') {
            s[idx] = s[i];
            idx++;
        }
        else if (s[i] == '#' && idx >= 0) {
            idx--;
        }
        if (idx < 0)
            idx = 0;
    }
 
    return s.substr(0, idx);
}
bool backspaceStringCompare(string s, string t){
    // int n=s.size();
    // int m=t.size();
    // stack<int>st;
    // stack<int>st1;
    // st1.push(t[0]);
    // st.push(s[0]);
    // for(int i=1 ; i<n ; i++){
    //     if(st.empty() && s[i]=='#'){
    //         continue;
    //     }
    //     else if(st.empty()==false && s[i]=='#'){
    //         st.pop();
    //     }
    //     else{
    //         st1.push(s[i]);
    //     }
    // }

    // for(int i=1 ; i<n ; i++){
    //     if(st1.empty() && s[i]=='#'){
    //         continue;
    //     }
    //     else if(st1.empty()==false && s[i]=='#'){
    //         st1.pop();
    //     }
    //     else{
    //         st1.push(s[i]);
    //     }
    // }
    if(removeBackspaces(s)==removeBackspaces(t)){
        return true;
    }
    return false;
}

int main(){
    int tests;
    cin >> tests;
    while (tests--) {
        string S, T;
        cin >> S;
        cin >> T;
        bool result = backspaceStringCompare(S, T);
        if (result) {
            cout << "true" << "\n";
        }
        else {
            cout << "false" << "\n";
        }
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