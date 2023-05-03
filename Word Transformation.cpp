#include <bits/stdc++.h>
using namespace std;

class WordLadder {
    public:
        int ladderLength(string bgn, string end, vector<string> avail) {
        set<string>st;
        for(auto& x:avail)
            st.insert(x);
        queue<pair<string,int>>q;
        q.push({bgn,1});
        while(!q.empty()){
            string curr=q.front().first;
            int lvl=q.front().second;
            q.pop();
            for(int i=0;i<curr.length();i++){
                string temp=curr;
                for(char c='a';c<='z';c++){
                    temp[i]=c;
                    if(st.find(temp)!=st.end()){
                        if(temp==end)
                            return lvl+1;
                        else{
                            q.push({temp,lvl+1});
                            st.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
        }
};

int main() {
    string beginWord, endWord;
    cin >> beginWord >> endWord;
    int n;
    cin >> n;
    vector<string> wordList;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        wordList.push_back(s);
    }
    int result = WordLadder().ladderLength(beginWord, endWord, wordList);
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