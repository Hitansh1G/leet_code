class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int count=0;
        int low=0, high=m-1;
        for(int i=0 ; i<n ; i++){
            if(grid[i][high]>=0) continue;
            if(grid[i][0]<0){
                count=count+(n-i)*(m);
                break;
            }
            low = 0 ;
            high = m-1;
            while(low<high){
                int mid=(low+high)/2;
                if(grid[i][mid]<0)high=mid;
                else low = mid+1;
            }
            count += (m-high);
        }
        return count;
    }
};