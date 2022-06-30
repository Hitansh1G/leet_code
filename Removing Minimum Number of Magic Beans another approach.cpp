class Solution {
public:
    long long minimumRemoval(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<long long> prefix(n, 0);
        prefix[0] = arr[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] + arr[i];
        }
        long long total_sum = prefix[n - 1];
        long long mini = LLONG_MAX;
        for(int i = 0; i < n; i++){
            long long curr_removal = 0;
            if(i > 0){
                curr_removal += prefix[i - 1];
            }
            long long right_sum = total_sum - prefix[i];
            curr_removal += right_sum - (long long)(n - i - 1) * (long long) arr[i];   
            mini = min(mini, curr_removal);
        }
        return mini;
    }
};