class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> sol;
        sol.reserve(m + n);
        for (int i = 0; i < m; i++) {
            sol.push_back(nums1[i]);
        }
        for (int i = 0; i < n; i++) {
            sol.push_back(nums2[i]);
        }
        sort(sol.begin(), sol.end());
        for (int i = 0; i < m + n; i++) {
            nums1[i] = sol[i];
        }
    }
};