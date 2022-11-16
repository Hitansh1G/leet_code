class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        int a[26] = {0};
        for(int i = 0;i<n;i++){
            a[s[i] - 'a'] = i;    
        }
        vector<int> ans;
        int min = 0,max = 0;
        for(int i = 0;i<n;i++){
            if(a[s[i] - 'a'] > max){
                max = a[s[i] - 'a'];
            }
            else if(i == max){
                ans.emplace_back(max - min + 1);
                max = min = i + 1;
            }
        }
        return ans;
    }
};