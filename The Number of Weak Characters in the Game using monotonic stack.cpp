bool accToSecond(vector<int>&first, vector<int> &second) {
	if (first[0] == second[0]) return first[1] < second[1];
	return first[0] > second[0];
}
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), accToSecond);
        stack<int> st;
        st.push(properties[0][1]);
        int n = properties.size();
        int ct = 0;
        for (int i = 1; i < n; i++) {
            int second =  properties[i][1];
            if (st.top() > second) ct++;
            if (st.top() < second) {
                st.pop();
                st.push(second);
            }
        }
        return ct;
    }
}; 