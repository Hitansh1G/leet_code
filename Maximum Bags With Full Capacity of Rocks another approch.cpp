class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int ar) {
        vector<int>help;
        int cnt=0;
        for(int i=0;i<rocks.size();i++){
            help.push_back(capacity[i]-rocks[i]);
            
        }
        sort(help.begin(),help.end());
        for(int i=0;i<help.size();i++){
            int h=min(help[i],ar);
            help[i]-=h;
            ar-=h;
            if(ar==0)
                break;
        }
        for(int i=0;i<help.size();i++){
            if(help[i]==0)
                cnt++;
        }
        return cnt;
    }
};