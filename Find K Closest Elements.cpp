class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //k closest integers to x 
        //x may or may not exist in the array
        //if x exist in array include it too in the list 
        int left=0;
        int right = arr.size()-k;
        while(left<right){
            int mid = (left+right)/2;
            if(x-arr[mid] > arr[mid+k]-x){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        vector<int>result;
        for(int i=left ; i<left+k ; i++){
            result.push_back(arr[i]);
        }
        return result;
        
    }
};