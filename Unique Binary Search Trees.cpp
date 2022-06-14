class Solution {
public:
    int t[20];
    int numTrees(int n) {
        if(n==1 || n==0 ){
            return 1;
        }
        if(t[n]){
            return t[n];
        }
        int temp=0;
        for(int i=1 ; i<=n ; i++){
            temp += numTrees(i-1)*numTrees(n-i);
        }
        t[n]=temp;
        return t[n];
        
    }
};