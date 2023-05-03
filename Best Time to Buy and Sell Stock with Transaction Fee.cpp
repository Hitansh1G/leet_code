class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int N = prices.size();
		vector<int> ahead(2,0),curr(2,0);
		for(int ind=N-1;ind>=0;ind--){
			for(int buy=0;buy<2;buy++){
				long profit = 0;
				
				if(buy==0) profit = max(-prices[ind] + ahead[1],ahead[0]);
		
				else profit = max(prices[ind] - fee + ahead[0],ahead[1]);
		
				curr[buy] = profit;
			}
			ahead = curr;
		}
		return curr[0];
	}
};