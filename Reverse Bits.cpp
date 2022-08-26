class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        long long ans=0;
        int cnt=31;
        while(n){
            int temp = n&1;
            ans=ans+(pow(2,cnt--)*temp);
            n=n>>1;
        }
        return ans;
    }
};