class Solution{
public:
    long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1, int k2){
        int n = nums1.size();
        map<long long, long long> m;
        for (int i = 0; i < n; i++){
            m[abs(nums1[i] - nums2[i])]++;
        }
        int op = k1 + k2;
        map<long long, long long>::reverse_iterator rit;
        for (rit = m.rbegin(); !m.empty() &&op > 0 && rit != m.rend();){
            if (op >= rit->second){
                m[rit->first - 1] += rit->second;
                op-=rit->second;
                m.erase(rit->first);
            }
            else{
                m[rit->first - 1] += op;
                rit->second -= op;
                op = 0;
            }
        }
        if(m.empty())return 0;
        long long sum = 0;
        for (auto it : m){
            if(it.first>0)
            sum += it.first * it.first * it.second;
        }
        return sum;
    }
};