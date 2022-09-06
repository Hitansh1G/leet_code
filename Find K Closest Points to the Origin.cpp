#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosestPointsToOrigin(vector<vector<int>> points, int k){
    vector<vector<int>> ans;
    priority_queue<pair<double, int>, vector<pair<double,int>>, greater<pair<double, int>> > pq;
    for(int i=0 ; i<points.size() ; i++){
        double dist = sqrt(pow(points[i][0],2) + pow(points[i][1], 2));
        pq.push({dist,i});
    }
    while(k--){
        pair<double,int>p = pq.top();
        ans.push_back(points[p.second]);
        pq.pop();
    }
    return ans;
}


int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1];
    }

    vector<vector<int>> closestPoints = kClosestPointsToOrigin(points, k);
    for (auto point : closestPoints)
    {
        for (auto value : point)
        {
            cout << value << " ";
        }
        cout << endl;
    }
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