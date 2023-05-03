class Solution {
public:
    vector<vector<int>>res;
    
    void solve(vector<int>ans,int k , int i , int target, int n,int sum){
        if(ans.size()==k && sum==target){
            res.push_back(ans);
            return;
        }
        if(i>n || sum>target || ans.size()>k)
            return;
        ans.push_back(i);
        sum+=i;
        solve(ans,k,i+1,target,n,sum);
        sum-=i;
        ans.pop_back();
        
        solve(ans,k,i+1,target,n,sum);
    }

    vector<vector<int>> combinationSum3(int k, int target) {        
        int n=9;
        vector<int>ans;
        solve(ans,k,1,target,n,0);
        return res;
    }
};