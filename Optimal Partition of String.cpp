class Solution {
public:
        struct comp {
        template <typename T>

        // Comparator function
        bool operator()(const T& l,const T& r) const{
            if (l.second != r.second) {
                return l.second < r.second;
            }
            return l.first < r.first;
        }
    };
    void sort(map<int, int>& M){
        set<pair<int, int>, comp> S(M.begin(), M.end());
    }


    int partitionString(string s) {
        string str = "";
        int n = s.size();
        int sol = 1;
        map<char,int>mp;
        
        for(int i=0 ; i<n ; i++){
            if(mp.find(s[i])==mp.end()){
                str+=s[i];
            }
            else{
                sol++;
                
                str="";
                str=str+s[i];
                
                mp.clear();
            }
            mp[s[i]]++;
        }
        // sort(mp);
        return sol;
    }
};
/*
a ko le ya na le
*/