class Solution {
public:
	int findPaths(int m, int n, int N, int i, int j) {
		int mod=1e9+7;
		vector<vector<int>> dp(m,vector<int>(n,0));
	   vector<int> dir{1,0,-1,0,1};
		for(int i=1;i<=N;i++){
			vector<vector<int>> temp(m,vector<int>(n,0));
			for(int x=0;x<m;x++){
				for(int y=0;y<n;y++){
					for(int d=0;d<4;d++){
						int a=x+dir[d];
						int b=y+dir[d+1];
						if(a<0 || b<0 || a>=m || b>=n){
							temp[x][y]+=1;
						}
						else{
							temp[x][y]=(temp[x][y]+dp[a][b])%mod;
						}
					}
				}
			}
			dp=temp;
		}

		return dp[i][j];

	}
};