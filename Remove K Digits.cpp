class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int c=0;
        if(k==0)
            return num;
        if(k>=num.size())
            return "0";
        for(int i=0;i<num.size();i++){
            while(c<k && !st.empty() && st.top()>num[i]){
                st.pop();
                c++;
            }
            st.push(num[i]);
            if(num[i]=='0' && st.size()==1)
                st.pop();
        }
        string s="";
        while(c<k && !st.empty()){
            c++;
            st.pop();
        }
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        if(s.size()==0)
            return "0";
        return s;
    }
};