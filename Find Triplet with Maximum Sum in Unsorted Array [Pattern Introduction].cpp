#include <bits/stdc++.h>
using namespace std;

long long int maxSumTriplet(int n, vector<int> &arr){
        long maxSum=0;
        for(int i=1;i<n-1;i++){
            long leftMax=0;
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i] && arr[j]>leftMax){
                    leftMax=arr[j];
                }
            }
            if(leftMax==0){
                continue;
            }
            long rightMax=0;
            for(int j=i+1;j<n;j++){
                if(arr[j]>arr[i] && arr[j]>rightMax){
                    rightMax=arr[j];
                }
            }
            if(rightMax==0){
                continue;
            }
            long sum=leftMax + arr[i]+ rightMax;
            if(sum>maxSum){
                maxSum=sum;
            }

        }
        return maxSum;
        
    
}
// tatic long maxSumTriplet(int n, long arr[]) {

//         long maxSum=0;


//         for(int i=1;i<n-1;i++){


//             long leftMax=0;

//             for(int j=0;j<i;j++){

//                 if(arr[j]<arr[i] && arr[j]>leftMax){
//                     leftMax=arr[j];
//                 }
//             }

//             if(leftMax==0){
//                 continue;
//             }


//             long rightMax=0;

//             for(int j=i+1;j<n;j++){
//                 if(arr[j]>arr[i] && arr[j]>rightMax){
//                     rightMax=arr[j];
//                 }
//             }

//             if(rightMax==0){
//                 continue;
//             }

//             long sum=leftMax + arr[i]+ rightMax;

//             if(sum>maxSum){
//                 maxSum=sum;
//             }

//         }

//         return maxSum;
//     }
// }

int main(){
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        long long int ans = maxSumTriplet(n, nums);
        cout << ans << endl;
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