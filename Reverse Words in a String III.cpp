class Solution {
public:
    void reverseString(string &s, int i, int j){
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
    
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        int j = 1;
        
        while(1){
            if(j==n){
                break;
            }
            if(s[j]==' '){
                reverseString(s, i, j-1);
                i = j+1;
                j = j+1;
            }
            else{
                j++;
            }
        }
        reverseString(s, i, j-1);
    return s;
    }
};
