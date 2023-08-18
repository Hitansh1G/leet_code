struct hash_pair
{
    template <class T1,class T2>
    size_t operator()(const pair<T1,T2>& p)const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if(hash1!=hash2)
        {
            return hash1^hash2;
        }
        return hash1;
    }
};
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> track(n,0);
        //unordered_set<pair<int,int>> st;
        unordered_map<pair<int,int>,bool,hash_pair> mp;
        for(auto i:roads)
        {
            track[i[0]]++;
            track[i[1]]++;
            //st.insert(make_pair(i[1],i[2]));
            mp[make_pair(i[0],i[1])] = true;
            mp[make_pair(i[1],i[0])] = true; 
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int currans = track[i]+track[j];
                if(mp.find(make_pair(i,j))!=mp.end())
                currans--;

                ans=max(ans,currans);
            }
        }
        return ans;
    }
};