class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nge;
        stack<int> s;
        for(int i=nums2.size()-1;i>=0;i--){
            
            while(!s.empty() && nums2[i] > s.top()) s.pop();
            
            if(s.empty()) nge[nums2[i]] = -1;
            else nge[nums2[i]] = s.top();
            
            s.push(nums2[i]);
        }
        
        vector<int> ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            ans[i] = nge[nums1[i]];
        }
        
        return ans;
    }
};