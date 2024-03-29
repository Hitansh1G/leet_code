class Solution {
    bool ispossible(int n, long long mid, vector<int>& batteries){
        long long m = batteries.size(), val = 0, check = (long long)n*mid;
        for(int i = 0; i < m; i++){
            if(batteries[i] < mid)
                val += batteries[i];
            else
                val += mid;
        }
        if(val >= check) return true;
        else return false;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        int mn = batteries[0];
        for(int &num : batteries){
            sum += num;
            mn = min(mn, num);
        }
        long long left = mn, right = (sum/n) + 1, ans = -1;
        while(left <= right){
            long long mid = left + (right-left)/2;
            if(ispossible(n, mid, batteries)){
                ans = mid;
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        } 
        return ans;
    }
};