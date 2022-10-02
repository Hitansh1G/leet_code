#include <bits/stdc++.h>
using namespace std;

class DecodeWays {
    public:
        // Implement Your Solution Here
        int numDecodings(string s) {
            int n=s.size();
            vector<int> dp(n+1);
            dp[0]=1;
            // dp[1]= s[0]=='0' ? 0 : 1;
            if(s[0]=='0') dp[1]=0;
            else dp[1]=1;
            for(int i=2 ; i<=n ; i++){
                int oneDigit = (s[i-1]-'0')%1000000007;
                int twoDigit = ((s[i-2]-'0')*10+(s[i-1]-'0'))%1000000007;
                if(oneDigit>=1) dp[i]+=dp[i-1]%1000000007;
                if(twoDigit>=10 && twoDigit<=26) dp[i]+=dp[i-2]%1000000007;
            }
            return dp[n]%1000000007;
        }
};

int main() {
    string s;
    cin >> s;
    int result = DecodeWays().numDecodings(s);
    cout << result;
    return 0;
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