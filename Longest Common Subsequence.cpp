class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> front(text2.size()+1,0),curr(text2.size()+1,0);
        for(int i=0;i<=text2.size();i++)front[i]=0;
        
        for(int ind1=1;ind1<=text1.size();ind1++){
            for(int ind2=1;ind2<=text2.size();ind2++){
                if(text1[ind1-1]==text2[ind2-1])curr[ind2]=1+front[ind2-1];
                else curr[ind2]=max(front[ind2],curr[ind2-1]);
            }
            front=curr;
        }
        return front[text2.size()];
    }
};