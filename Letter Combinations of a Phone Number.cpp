#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
#include <bits/stdc++.h>
using namespace std;

class LetterCombinationsOfPhoneNumber {
  public:

    vector<string> letterCombinationsOfPhoneNumber(string digits) {

        if(digits.size()==0){
            return {};
        }
        map<char,string>m;
        m['2'] = "abc";
        m['4'] = "ghi";
        m['3'] = "def";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";

        int size = 1;
        for(int i=0; i<digits.size(); i++){
            size *= m[digits[i]].size();
        }
        int itr = size;
        vector<string> ans(size,"");
        
        for(int i=0; i<digits.size(); i++){
            int temp = i,k=0, count=0;
            itr /= m[digits[i]].size();
            
            if(itr == 0) itr = 1;
            
            for(int j=0; j<size; j++){
                if(count == itr){
                    k++;
                    if(k == m[digits[i]].size()) k = 0;
                    count = 0;
                }
                ans[j] += m[digits[i]][k];
                count++;
            }
        }
        return ans;
    }
};

int main() {
    FastIO();
    string digits;
    cin >> digits;
    vector<string> combinations =
        LetterCombinationsOfPhoneNumber().letterCombinationsOfPhoneNumber(digits);
    PrintMatrix<string>().OneDMatrix(combinations, " ");
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