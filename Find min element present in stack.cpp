#include <bits/stdc++.h>
using namespace std;

stack<int> S , minstack;

void push( int x) {
    S.push(x);
    if (minstack.empty() || minstack.top() >= x) {
        minstack.push(x);
    }
}

void pop() {
    if ( !minstack.empty() && S.top() == minstack.top() ) {
        minstack.pop();
    }
    if ( !S.empty()) S.pop();
}

int findMin() {
    if (S.empty() || minstack.empty()) return -1;
    return minstack.top();
}

int main()
{
    int n, m, t;
    cin >> t;
    while (t--) {
        int ch;
        cin >> ch;
        if ( ch  == 1) {
            cin >> n;
            push(n);
        }
        else if ( ch == 2)
            pop();
        else
            cout << findMin() << endl;
    }

}
// stack< long long int > s,minstack;
// void push( int x) {
//     s.push((long long int)x);
// }

// void pop() {
//     s.pop();
// }

// int findMin() {
//     minstack=s;
//     long long int minimum = INT_MAX;
//     while(minstack.empty()==false){
//         minimum = min(minimum,minstack.top());
//         minstack.pop();
//     }
//     if(minimum==INT_MAX)return -1;
//     return minimum;
// }







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