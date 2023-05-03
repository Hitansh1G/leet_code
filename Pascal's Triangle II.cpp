class Solution {
public:
	vector<int> getRow(int rowIndex) {
		int **a = new int *[rowIndex + 1];
		for(int i = 0; i <= rowIndex; i ++) a[i]= new int [rowIndex + 1];
		for(int i = 0; i <= rowIndex; i ++){
			a[i][0] = 1;
			a[i][i] = 1;
		}
		for(int i = 2; i <= rowIndex; i ++)
			for (int j = 1; j < i; j ++)
				a[i][j] = a[i-1][j] + a[i-1][j-1];
		vector<int> outv;
		for(int i = 0; i <= rowIndex; i ++) 
            outv.push_back(a[rowIndex][i]);
		return outv;
	}
};