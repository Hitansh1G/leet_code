class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.size();
        vector<int> ans(m);
        for(int i=0; i<m; i++){
            int x = startPos[0];
            int y = startPos[1];
            int count  = 0;
            for(int j=i; j<m; j++){
                char c = s[j];
                if(c=='L'){
                    if(y==0)
                        break;
                    else y--;
                }
                if(c=='R'){
                    if(y==n-1)
                        break;
                    else y++;
                }
                if(c=='U'){
                    if(x==0)
                        break;
                    else x--;
                }
                if(c=='D'){
                    if(x==n-1)
                        break;
                    else x++;
                }
                count++;
            }
            ans[i] = count;
        }
        return ans;
    }
};