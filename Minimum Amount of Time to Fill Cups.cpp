class Solution {
public:
    
        // int binpow(int a, int b){
        // int res = 1;
        // while (b > 0) {
        //    if (b & 1)
        //        res = res * a;
        //    a = a * a;
        //    b >>= 1;
        // }
        // return res;
        // }
        int gcd (int a, int b) {
            return b ? gcd (b, a % b) : a;
        }
        // int lcm (int a, int b) {
        //     return a / gcd(a, b) * b;
        // }
    int fillCups(vector<int>& nums) {
        // bool flag = compareInterval(nums[1],nums[2]);
        // binpow(nums[1],nums[2]);
        gcd(nums[1],nums[2]);
        // lcm(nums[1],nums[2]);
        int temp=0;
        sort(nums.begin(), nums.end());
        while(nums[0]!=0 && nums[1]!=0){
            
            temp++;
            nums[1]--;
            nums[2]--;
            
            sort(nums.begin(), nums.end());
        }
        sort(nums.begin(), nums.end());
        temp+=nums[2];
        return temp;
        
    }
};