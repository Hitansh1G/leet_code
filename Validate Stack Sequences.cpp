class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        int m=popped.size();
        stack<int>st;
        // int i=0;
        // while(i!=n){
        //     st.push(pushed[i]);
        //     i++;
        // }
        // //traverse in stack from the top 
        // int prev;
        // for(int i=0 ; i<m ; i++){
        //     while(st.top()!=popped[i]){
        //         prev = st.top();
        //         st.pop();
        //     }
        //     if(prev != popped[i+1])
        // }
        int j=0;
        for(int i=0 ; i<n ; i++){
            st.push(pushed[i]);
            while(!st.empty() && j<popped.size() && st.top()==popped[j]){
                st.pop();
                j++;
            }
        }
        if(j==popped.size())return true;;
        return false;

    }
};