class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> ans;
        ans.push_back(a[0]);
        for(int i=1;i<a.size();i++){
            if(ans.empty() || ans.back()<0 || a[i]>0)
                ans.push_back(a[i]);
            else{
                int x = a[i];
                while(true){
                    if(ans.empty() || ans.back()<0){
                        ans.push_back(x);
                        break;
                    }
                    if(ans.back()==-1*x){
                        ans.pop_back();
                        break;
                    }
                    else if(ans.back()>-1*x)
                        break;
                    else if(ans.back()<-1*x)
                        ans.pop_back();
                }
            }
        }
        return ans;
    }
};