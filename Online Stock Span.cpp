class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        st.push(make_pair(1e5,0));
    }
    
    int next(int price) {
        int ind = st.top().second+1;
        while(st.top().first<=price){
            st.pop();
        }
        int ans=ind-st.top().second;
        st.push(make_pair(price,ind));
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */