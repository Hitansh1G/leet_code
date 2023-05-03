class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<int> prev(amount+1,0);
        vector<int>curr(amount+1,0); 
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0)
                prev[t]= 1;
            else prev[t]= 0;
        }
        
        for(int i=1;i<n;i++){
            for(int tar=0;tar<=amount;tar++){
                
                int take=0;
                int notTake= prev[tar];
                if(tar>=coins[i])
                    take= curr[tar-coins[i]];
                 curr[tar]= (take+notTake);
            }
            prev=curr;
        }
       return prev[amount];
        
    }
};