#include <bits/stdc++.h> 
using namespace std; 


// Implement your solution Here
void helper(int n, char a, char b, char c,vector<string>&ans){
	if(n==1){
		string temp = to_string(n);
		string str = temp+" "+a+" "+c;
		ans.push_back(str);
		return;
	}
	helper(n-1,a,c,b,ans);
	string temp = to_string(n);
	string str = temp+" "+a+" "+c;
	ans.push_back(str);
	helper(n-1,b,a,c,ans);
}
vector<string> towerOfHanoi(int n)
{
	vector<string> ans;

	//shift n-1 disks from a to b
	//shift last disk from a to c
	//shift n-1 disk from b to c
	char a='A',b='B',c='C';
	helper(n,a,b,c,ans);
	return ans;
} 

int main() 
{ 
	int n;
	cin>>n;
	vector<string> ans=towerOfHanoi(n);
	for(auto i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<"\n";
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