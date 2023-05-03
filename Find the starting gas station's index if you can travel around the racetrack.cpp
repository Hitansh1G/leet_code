#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<int,int> &a,const pair<int,int> &b){
       return a.second<b.second;
}
long long CircularRace(long long n,vector<long long > gas, vector<long long > cost){
    // int curr=0;
    // int totalfuel=0;
    // int totalcost=0;
    // int diff =0,start=0;
    // for(int i=0 ; i<n ; i++){
    //     totalfuel+= gas[i];
    //     totalcost-= burn[i];
    // }
    // if(totalfuel<totalcost) return -1;
    // for(int i=0 ; i<n ; i++){
    //     curr += (gas[i]-burn[i]);
    //     if(curr<0){
    //         start = i+1;
    //         curr=0;
    //     }
    // }
    // return start+1;;
    if(n==0){
		return -1;
	}
			   	
	if(n==1){
        if(cost[0]==gas[0])return 1;
		return gas[0]-cost[0]<0?-1:0;
	}
			
	int start = 0;
	int end = 1;
	int curr= gas[0]-cost[0];
	while(start!=end) {
        while(curr<0 && start!=end) {
            curr= curr- (gas[start]-cost[start]);
            start = (start+1)%n;
            if(start==0)
                return -1;
        }
        curr+= gas[end]-cost[end];
        end = (end+1)%n;
    }
    if(curr<0)
        return -1;
    return start+1; 
}


int main()
{
    int n;
    cin>>n;
    vector<long long > gas(n),burn(n);
    for(int i=0;i<n;i++)
        cin>>gas[i];
    for(int i=0;i<n;i++)
        cin>>burn[i];
    int result = CircularRace(n, gas,  burn); 
    cout<<result<<"\n";
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