#include <bits/stdc++.h> 
using namespace std;  
int editDistance(string str1, string str2) 
{ 
     int n=str1.size();
     int m=str2.size();

     int dp[n+1][m+1];

     for(int i=0;i<=n;i++)
          dp[i][0]=i;
     for(int i=0;i<=m;i++)
          dp[0][i]=i;

     for(int i=1 ; i<n+1 ; i++){
          for(int j=1 ; j<m+1 ; j++){
               if(str1[i-1]==str2[j-1]){
                    dp[i][j] = (dp[i-1][j-1]);
               }
               else{
                    dp[i][j] = 1 + min ( {dp[i-1][j] ,dp[i][j-1] ,dp[i-1][j-1]  });
               }
          }
     }
     return dp[n][m];
} 
int main() 
{
	string str1,str2;
	cin>>str1;
	cin>>str2;
	cout << editDistance(str1, str2);
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