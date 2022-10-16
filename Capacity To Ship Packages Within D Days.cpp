class Solution {
public:
    int fun(int mid , int sum , vector<int>& arr, int days){
        //return the no of days which is taking
        int n=arr.size();
        // vector<int>flag;
        int temp =0;
        int count=1;
        for(int i=0 ; i<n ; i++){
            if(arr[i]>mid)return INT_MAX;
            temp += arr[i];
            if(temp>mid){
                // flag.push_back(temp);
                count++;
                temp=arr[i];
                
            }
        }
        cout<<mid<<" "<<count<<endl;
        return count;
    }
    /*
    mid = 3
    temp=0
    count=2
    */
    int shipWithinDays(vector<int>& arr, int days) {
        int n = arr.size();
        int sum=0;
        for(int i=0 ; i<n ; i++){
            sum += arr[i];
        }
        int left = 0;
        int right = sum;
        int temp;
        while(left<=right){
            int mid = (left+right)/2;
            temp = fun(mid,sum,arr,days);
            if(temp <= days){
                //move left
                right = mid-1;
            }
            else {
                //move right
                left = mid+1;
            }
        }
        return left;
    }
};
// 1 2 3 1 1
// 1 2
// 3
// 1 1
/*
1 2 3 1 1
mid = 3
left = 3
right = 2
temp = 3

*/