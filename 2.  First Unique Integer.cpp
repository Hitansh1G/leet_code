#include<bits/stdc++.h>
using namespace std;
// bool cmp(pair<int, int>& a, pair<int, int>& b)
// {
//     return a.second < b.second;
// }
// void sort(map<int, int>& M){
  
//     vector<pair<int, int> > A;
//     for (auto& it : M) {
//         A.push_back(it);
//     }
//     sort(A.begin(), A.end(), cmp);
// }
int firstUniqueInteger(vector<int> &v) {
	int result=-1;
	unordered_map<int,int>mp;
	for(int i=0 ; i<v.size() ; i++){
		mp[v[i]]++;
	}

	for(int i=0 ; i<v.size() ; i++){
		if(mp[v[i]]==1){
			return v[i];
		}
	}
	return -1;
}
int main() {
	int n, m;
	cin >> n;
	vector<int> v(n);
	for ( int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int ans = firstUniqueInteger(v);
	cout << ans << endl;
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