#include <bits/stdc++.h>
using namespace std;

class WordSearch {
  public:
    bool solve(vector<vector<char>>&board, string &word, int i, int j, int idx){
        if(idx == word.size()) return true;
        if(j<0|| i<0 || i==board.size() || j==board[0].size()) return false;
        if(board[i][j]==word[idx]){
            board[i][j]='0';
            bool left = solve(board,word,i,j-1,idx+1);
            bool right = solve(board,word,i,j+1,idx+1);
            bool up = solve(board,word,i-1,j,idx+1);
            bool down = solve(board,word,i+1,j,idx+1);
            if(left||right||up||down)return true;
            board[i][j]=word[idx];
        }
        return false;
    }
    bool exist(vector<vector<char>> &board, string &word) {
        for(int i=0;i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]==word[0]){
                    if(solve(board, word, i, j, 0))return true;
                    continue;
                }
            }
        }
        return false;

    }
};

int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<char>> grid(row,vector<char> (col));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            cin>>grid[i][j];
    }
    string word;
    cin >> word;
    bool result = WordSearch().exist(grid, word);
    if(result == true)
        cout<<"true";
    else
        cout<<"false";
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