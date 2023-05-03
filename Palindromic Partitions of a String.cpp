#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s,int st,int ed){
	while(st<ed){
		if(s[st++]!=s[ed--]) return false;
	}
	return true;
}
void solve(int ind,int n,string s,vector<vector<string>>& ans,vector<string>& temp){
        if(ind==n){
            ans.push_back(temp);
            return;
        }
        for(int i=ind ; i<n ; i++){
            if(isPalindrome(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                solve(i+1,n,s,ans,temp);
                temp.pop_back();
            }
        }
    }
vector<vector<string> > palindromePartitioning(string s)
{
	vector<vector<string>>ans;
	vector<string>temp;
	solve(0,s.length(),s,ans,temp);
	return ans;
}
int main()
{
	string s;
	cin >> s;
	vector<vector<string> > ans = palindromePartitioning(s);
	for(auto it = 0; it < ans.size(); it++) {
		for(auto pt = 0; pt < ans[it].size(); pt++) {
			cout << ans[it][pt] << " ";
		}
		cout << "\n";
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