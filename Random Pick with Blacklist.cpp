class Solution{
    
public:
    unordered_set<int> ispresent; 
    vector<pair<int, int>> not_present; 
    int n;
    
    Solution(int N, vector<int>& b){
        n = N;
        if(b.size()==0)
            return;
        sort(b.begin(), b.end()); 
        if(b[0])
            not_present.push_back({0, b[0]});
        ispresent.insert(b[0]); 
        
        for(int i=1;i<b.size();i++){
            ispresent.insert(b[i]);
            if(b[i]-1!=b[i-1])
                not_present.push_back({b[i-1]+1, b[i]-b[i-1]-1}); 
        }
        if(b[b.size()-1] != n-1)
            not_present.push_back({b[b.size()-1]+1, n-1-b[b.size()-1]}); 
    }
    
    int pick(){
        int pk = rand();
		int el = pk%n;
        if(ispresent.find(el)==ispresent.end())
            return el;
        int sz = not_present.size();
        pk = pk%sz; 
        int f = not_present[pk].first + rand()%(not_present[pk].second); 
        return f;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */