class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        // int n=nums.size();
        // set<int>st;
        // for(int i=0 ; i<n ; i++){
        //     st.insert(nums[i]);
        // }
        // int temp=0;
        // long long sum=0;
        // for(int i=1 ; i<INT_MAX ; i++){
        //     if(temp >= k) break;

        //     if(st.find(i)!=st.end()){
        //         continue;
        //     }
        //     else{
        //         temp++;
        //         nums.push_back(i);
        //         sum+=i;
        //         cout<<i<<" ";
        //     }
        // }
        // // long long sum=0;
        // // for(long long i=0 ; i<n ; i++){
        // //     sum+= nums[i];
        // // }
        // return sum;

        set<int>s(nums.begin(),nums.end());
        long long ans = (long(k)*(long(k+1)))/2; 
        for(auto i:s){
            if(i<=k){ 
                ans+=k+1;
                ans-=i;
                k++;
            }
            else  
                break;
        }
        return ans;
    
    }
};