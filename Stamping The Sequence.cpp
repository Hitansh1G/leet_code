vector<int> buildPMT(string s){
    int n = s.length();
    int j = 0;
    vector<int> pmt(n, 0);
    for(int i = 1; i < n; ++i){
        while(j > 0 && s[i] != s[j]){ j = pmt[j-1]; }
        if(s[i] == s[j]){ pmt[i] = ++j; }
    }
    return pmt;
}

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        s = stamp;
        t = target;
        slen = s.length();
        tlen = t.length();
        pmt = buildPMT(s);
        ans.clear();
        
        bool success = divideConquer(0, tlen);
        if(!success) return {};
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    bool divideConquer(int start, int end) {
        if(start >= end) { return true; }
        
        int idx = kmpFind(start, end);
        if(idx >= 0){
            ans.push_back(idx);
            return divideConquer(start, idx) && divideConquer(idx+slen, end);
        }
        
        while(start < end){
            idx = bfFind(start, end);
            if(idx < 0) { return false; }
            ans.push_back(idx);
            if(idx < start) { start = idx + slen; }
            else { end = idx; }
        }
        
        return true;
    }
    int kmpFind(int start, int end) {
        for(int i=start, j=0; i<end; ++i){
            while(j > 0 && t[i] != s[j]){ j = pmt[j-1]; }
            if(t[i] == s[j] && ++j == slen){ return i + 1 - slen; }
        }
        return -1;
    }
    int bfFind(int start, int end) {
        int firstwin, lastwin;
        int i, j;
        firstwin = max(start+1-slen, 0);
        lastwin = min(start-1, tlen-slen);
        for(int winstart = lastwin; winstart >= firstwin; --winstart){
            for(j=start-winstart, i=start; 
                j<slen && (i>=end || t[i]==s[j]); 
                ++j, ++i);
            if(j == slen){ return winstart; }
        }
        firstwin = max(end-slen, 0);
        lastwin = min(end-1, tlen-slen);
        for(int winstart = firstwin; winstart <= lastwin; ++winstart){
            for(j=0, i=winstart; 
                i<end && (i<start || t[i]==s[j]); 
                ++j, ++i);
            if(i == end){ return winstart; }
        }
        
        return -1;
    }
    
    string s;
    string t;
    int slen;
    int tlen;
    vector<int> pmt;
    vector<int> ans;
};