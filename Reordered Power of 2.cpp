class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<string> power;
        for(int i=0;i<=30;i++){
            int a=pow(2,i);
            power.push_back(to_string(a));
        }
        for(int i=0;i<=30;i++){
            sort(power[i].begin(),power[i].end());
        }
        string s=to_string(n);
        sort(s.begin(),s.end());

        for(int i=0;i<=30;i++){
            if(s==power[i]){
                return true;
            }
        }
        return false;
    }
};