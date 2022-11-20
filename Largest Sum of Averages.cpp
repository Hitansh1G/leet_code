class Solution {

    double SolveByMemo(vector<int>& nums, int index , int k, vector<vector<double>>& dp){
        if(index == nums.size())
            return 0;

        if(dp[index][k] != -1)
        return dp[index][k] ;

        if(k == 1){
            double sum = 0;
            for(int i = index ; i<nums.size() ; i++)
             sum+= nums[i];
             
             return dp[index][k] = sum/(nums.size()-index);
        }

        double maxi = 0;
        double curr_avg = 0;
        for(int i = index ; i<=nums.size()-k ; i++){
            curr_avg+= nums[i];
            maxi = max(maxi , (curr_avg/(i-index+1)) + SolveByMemo(nums, i+1 , k-1 , dp));
        }

        return dp[index][k] = maxi;
    }

     double SolveByTab(vector<int>& nums , int k){

       vector<vector<double>> dp(nums.size()+1 , vector<double> (k+1, 0));
        for(int m = nums.size()-1 ; m>= 0 ; m--){
             for(int n = 1 ; n <= k ; n++){
                  if(n == 1){
                      double sum = 0;
                       for(int i = m ; i<nums.size() ; i++)
                        sum+= nums[i];
             
                        dp[m][n] = sum/(nums.size()-m);
                       continue ;
                 }

                 double maxi = 0;
                 double curr_avg = 0;
                 for(int i = m ; i<= nums.size()-n ; i++)
                 {
                  curr_avg+= nums[i];
                  maxi = max(maxi , (curr_avg/(i-m+1)) + dp[i+1][n-1]);
                 }

                 dp[m][n] = maxi;
             }
        }

        return dp[0][k] ;
    }

public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        // vector<vector<double>> dp(nums.size() , vector<double> (k+1, -1));

        // return SolveByMemo(nums, 0 , k , dp);

        return SolveByTab(nums, k);
    }
};