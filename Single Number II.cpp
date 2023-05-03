class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int res = 0;
        for(int i = 0; i < 32; i++){
            int count = 0;
            int bmask = (1 << i);
            for(int val : nums){
                if((val & bmask) == bmask){
                    // ith bit is ON
                    count++;
                }
            }
            if(count % 3 != 0){
                // ON ith bit in res
                res = (res | bmask);
            }
        }
        return res;
        
        
    }
};