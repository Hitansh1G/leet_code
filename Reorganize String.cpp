class Solution {
public:
    string reorganizeString(string s) {
        int hash[26]={0};
        for(int i=0;i<s.length();i++)
            hash[s[i]-'a']++;
        
        char max_occ_char;
        int max_fre=INT_MIN;
        for(int i=0;i<26;i++)
        {
            if(hash[i]>max_fre)
            {
                max_fre=hash[i];
                max_occ_char=i+'a';
            }
        }

        int index=0;
        while(index<s.length() && max_fre>0)
        {
            s[index]=max_occ_char;
            index+=2;
            max_fre--;
        }

        if(max_fre!=0)
            return "";
        hash[max_occ_char-'a']=0;
        for(int i=0;i<26;i++)
        {
            while(hash[i]>0)
            {
                index=index>=s.length()?1:index;
                s[index]=i+'a';
                hash[i]--;
                index+=2;
            }
        }

        return s;
    }
};