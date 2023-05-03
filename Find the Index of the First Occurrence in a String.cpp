class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int>v;
        for(int i=0;i<haystack.size();i++){
            if(haystack[i]==needle[0])
            v.push_back(i);
        }
        if(v.size()==0)
            return -1;
        int size=needle.size();
        for(auto i:v){
            int a=i;
            bool flag=true;
            for(int j=0;j<needle.size() && flag ;j++){
                if(haystack[a++]==needle[j])
                size--;
                else
                flag=false;
            }
            if(size==0)
            return i;
            flag=true;
            size=needle.size();
        }
        return -1;
    }
};