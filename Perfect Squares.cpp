class Solution {
public:
    int solve(int i,int n,int target,vector<int> &v,vector<vector<int>> &vec)
    {
        if(i==n-1)
        {
            if(target%v[i]==0) return target/v[i];
            else return 1e8;
        }
        if(vec[i][target]!=-1)return vec[i][target];
        int notake=solve(i+1,n,target,v,vec);
        int take=1e8;
        if(v[i]<=target)
        take=1+solve(i,n,target-v[i],v,vec);
        return vec[i][target]=min(notake,take);
    }
    int numSquares(int n) {
        vector<int> v;
        for(int i=1;i<=100;i++)
            v.push_back(pow(i,2));
          int m=v.size();
        vector<vector<int>> vec(m+1,vector<int>(n+1,-1));
        return solve(0,m,n,v,vec);
    }
};