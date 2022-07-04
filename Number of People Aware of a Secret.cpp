class Solution {
public:
    #define ll long long
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<ll> v(n+1,0);
        //v store how many person knows the secret on ith day
        v[0] = 1; 
        int mod = 1000000007;
        for(int i=0 ; i<n ; i ++){
            if(v[i] == 0)
                continue;
            for(int j=i+delay ; j<n && (j-i)<forget ; j++){
                v[j] += v[i];
                v[j] = v[j]%mod;
            }
        }
        ll ans = 0;
        for(int i=n-1 ; i>=n-forget ; i--){
            ans += v[i];
            ans = ans%mod;
        }
        return ans;
    }
};