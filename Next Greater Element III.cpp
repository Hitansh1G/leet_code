class Solution {
public:
    int nextGreaterElement(int num) {
        string str = to_string(num);
        int n = str.size();
        int i = n - 2;
        while(i >= 0 && str[i] >= str[i + 1]){
            i--;
        }
        if(i < 0){
            return -1;
        }
        int j = n - 1;
        while(j >= 0){
            if(str[j] > str[i]){
                break;
            }   
            j--;
        }
        swap(str[i], str[j]);
        reverse(str.begin() + i + 1, str.end());
        long long res = stol(str);
        if(res > INT_MAX || res < INT_MIN)
            return -1;
        return res;
    }
};