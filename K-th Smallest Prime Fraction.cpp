class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
      
    
        priority_queue<pair<double, pair<int, int>>>ans;
        for(int i=0;i<arr.size()-1;i++){
          for(int j=i+1;j<arr.size();j++)
          { double x=(double)arr[i] /(double)arr[j];
           if(ans.size()<k)
           ans.push({x,{arr[i],arr[j]}});
           else if(ans.top().first>x)
           {
             ans.pop();
             ans.push({x,{arr[i],arr[j]}});
           }
           else continue;
          }
        }
          vector<int>res;
          res.push_back(ans.top().second.first);
          res.push_back(ans.top().second.second);
          return res;
        
    }
};