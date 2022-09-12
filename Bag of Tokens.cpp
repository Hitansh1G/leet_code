class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size() - 1;
        int score = 0;
        while(i <= j){
            if(tokens[i] <= power){
                score++;
                power = power - tokens[i];
                i++;
            }
            else if(score >= 1 and i < j){
                score--;
                power = power + tokens[j];
                j--;
            }
            else break;
        }
        return score;
    }
};