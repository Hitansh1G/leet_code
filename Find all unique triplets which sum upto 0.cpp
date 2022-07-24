#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"

using namespace std;


class ThreeSum {
public:
    vector<vector<int>> threeSum(vector<int>& nu) {
        vector<vector<int>> ans;
        sort(nu.begin(),nu.end());
        int n = nu.size();
        int a;
        for(int i = 0; i<n;i++){
            if(i == 0 || (i>0 && nu[i] != nu[i-1])){
                a = nu[i];
                int low = i+1 , hi = n-1;
                while(low<hi){
                    if(nu[low] + nu[hi] > -a) hi--;
                    else if(nu[low] + nu[hi] < -a) low++;
                    else{
                        ans.push_back({a,nu[low],nu[hi]});
                        while(low<hi && nu[low] == nu[low+1]) low++;
                        while(low<hi && nu[hi] == nu[hi-1]) hi--;
                        low++; hi--;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    FastIO();
    int n;
    cin >> n;
    vector<int> nums;
    ReadMatrix<int>().OneDMatrix(n, nums);

    vector<vector<int>> result = ThreeSum().threeSum(nums);
    for (unsigned int i = 0; i < result.size(); i++) {
        cout << result[i][0] << " " << result[i][1] << " " << result[i][2];
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