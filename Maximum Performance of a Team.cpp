class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
            v.push_back({efficiency[i],speed[i]});
        sort(v.begin(),v.end());
        long long int ans=0,sum=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=n-1;i>=0;i--)
        {
            pq.push({v[i].second,v[i].first});
            sum+=v[i].second;
            if(pq.size()>k)
            {
                sum-=pq.top().first;
                pq.pop();
            }
            ans=max(ans,1LL*sum*v[i].first);
        }
        return ans%1000000007;
    }
};