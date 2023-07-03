class Solution {
public:
    bool buddyStrings(string s, string goal) {
        map<char, int> mp;

        int n=s.size();
        int m=goal.size();

        if(n!=m)return false;


        for(int i=0 ; i<n ; i++) 
            mp[s[i]] = i;
    
        for(int i=0 ; i<m ; i++){
            if(mp.find(goal[i]) == mp.end()) 
                return false;
            if(mp[goal[i]] != i){
                swap( s[i], s[mp[goal[i]]]);
                if(s == goal) 
                    return true;
                swap(s[i], s[mp[goal[i]]]);
            }
        }
        return false;
    }
};