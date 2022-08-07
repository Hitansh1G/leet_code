class Solution {
public:
    int countVowelPermutation(int n) {
        int mod=1000000007;
        long long int arr[n][5];
        for(int i=0;i<5;i++){
            arr[0][i]=1;
        }
        for(int i=1;i<n;i++){
            arr[i][0]=arr[i-1][1]+arr[i-1][2]+arr[i-1][4];
            arr[i][0]%=mod;
            arr[i][1]=arr[i-1][0]+arr[i-1][2];  
            arr[i][1]%=mod;
            arr[i][2]=arr[i-1][1]+arr[i-1][3];
            arr[i][2]%=mod;
            arr[i][3]=arr[i-1][2];
            arr[i][3]%=mod;
            arr[i][4]=arr[i-1][2]+arr[i-1][3];
            arr[i][4]%=mod;
        }
        long long int ans=0;
        for(int i=0;i<5;i++){
            ans+=arr[n-1][i];
            ans%=mod;
        }
        return ans;
    }
};