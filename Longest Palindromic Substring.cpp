class Solution {
public:
    string longestPalindrome(string s) {
	    // Manacher's algo
        string ss = "#"; 
        for (auto& ch : s) {
            ss.push_back(ch); 
            ss.push_back('#'); 
        }
        
        int n = ss.size(), ii = 0, most = 0; 
        vector<int> hlen(n); 
        for (int i = 0, center = 0, right = 0; i < n; ++i) {
            if (i < right) hlen[i] = min(right-i, hlen[2*center-i]); 
            while (0 <= i-1-hlen[i] && i+1+hlen[i] < n && ss[i-1-hlen[i]] == ss[i+1+hlen[i]]) ++hlen[i]; 
            if (right < i+hlen[i]) center = i, right = i+hlen[i]; 
            if (most < hlen[i]) ii = i, most = hlen[i]; 
        }
        return s.substr((ii-most)/2, most); 
    }
};