class Solution {
public:
    int findDuplicate(vector<int>& v) {
      sort(v.begin(),v.end());
        int ans;
        for(int i=1;i<v.size();i++){
            if(v[i]==v[i-1]){
                ans=v[i]; 
                break;
            }
        }
        return ans;
    }
};