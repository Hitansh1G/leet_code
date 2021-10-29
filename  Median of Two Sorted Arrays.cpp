class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        vector<int> merged;
        int i;
        merged.insert(merged.begin(), nums1.begin(), nums1.end());
        merged.insert(merged.end(), nums2.begin(), nums2.end());
        sort(merged.begin(), merged.end());
        if(merged.size() % 2 == 0)
        {
            i = merged.size() / 2;
            return (double)( merged[i - 1] + merged[i] ) / 2;
        }
        else{
            i = merged.size() / 2;
            return (double) merged[i];
        }
    }
};