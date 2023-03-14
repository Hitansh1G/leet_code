class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        unordered_map<int,int> map;
        for(int i=0 ; i<nums1.size() ; i++) {
            map[nums1[i]]++;
        }
        int idx = 0;
        for(int i=0 ; i<nums2.size() ; i++) {
            if(map[nums2[i]] > 0){
                nums1[idx++] = nums2[i];
                --map[nums2[i]];
            }
        }
        return vector<int>(nums1.begin(), nums1.begin()+idx);
    }
};