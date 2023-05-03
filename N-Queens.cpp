class Solution {
public:
	vector<vector<string>> ans;
	bool isValid(vector<string>& a,int col,int row){
		for(int i=row-1;i>=0;--i){
			if(a[i][col]=='Q'){
				return false;
			}
		}
		for(int i=row-1,j=col-1;i>=0&&j>=0;--i,--j){
			if(a[i][j]=='Q'){
				return 0;
			}
		}
		for(int i=row-1,j=col+1;i>=0&&j<a.size();--i,++j){
			if(a[i][j]=='Q'){
				return 0;
			}
		}
		return 1;
	}
	void solve(int n,int row,vector<string>& a){
		if(row==n){
			ans.push_back(a);
			return;
		}
		for(int i=0;i<n;++i){
			if(isValid(a,i,row)){
				a[row][i] = 'Q';
				solve(n,row+1,a);
				a[row][i] = '.';
			}
		}
	}
	vector<vector<string>> solveNQueens(int n) {
		vector<string> a(n,string(n,'.'));
		solve(n,0,a);
		return ans;
	}
};