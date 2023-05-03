#include <bits/stdc++.h>
using namespace std;

string reverseWordsInAString(string s){
    
    int n = s.size();
        bool flag = true;
        int i = 0, e = n-1;
        while(i<e){
            if(flag && s[i] == ' '){
                s = s.substr(i+1);
                i = 0;
                e--;
            }
            else{
                flag = false;
                swap(s[i], s[e]);
                i++;
                e--;
            }
        }
        e=s.size();
        int p1 = 0, p2=0;
        while(p1<e){
            if(s[p1] == ' '){
                s = s.erase(p1, 1);
                e--;
            }
            else{
                while(p2<e && s[p2] != ' ') p2++;
                reverse(s.begin()+p1, s.begin()+p2);
                p1 = p2+1;
                p2 = p1;
            }            
        }
        return s;
}


int main(){
    string str;
    getline(cin, str);
    cout<<reverseWordsInAString(str);
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