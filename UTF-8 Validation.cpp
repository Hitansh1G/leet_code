class Solution {
public:
    string toBinary(int& num){
        string s = "";
        while(num){
            s += to_string(num%2);
            num /= 2;
        }
        while(s.size()<8){
            s.push_back('0');
        }
        reverse(s.begin(),s.end());
        return s;
    }
    
    bool validUtf8(vector<int>& data) {
        vector<string> bin;
        for(auto it : data){
            bin.push_back(toBinary(it));
        }
        bool flag = true;
        for(int i = 0;i<bin.size();){
            if(bin[i].substr(0,3)=="110" && i+1<bin.size() && bin[i+1].substr(0,2)=="10"){
                i += 2;
            }
            else if(bin[i].substr(0,4)=="1110" && i+2<bin.size() && bin[i+1].substr(0,2)=="10" && bin[i+2].substr(0,2)=="10"){
                i += 3;
            }
            else if(bin[i].substr(0,5)=="11110" && i+3<bin.size() && bin[i+1].substr(0,2)=="10" && bin[i+2].substr(0,2)=="10" && bin[i+3].substr(0,2)=="10"){
                i += 4;
            }
            else if(bin[i][0]=='0'){
                i++;
            }
            else{
                flag = false;
                break;
            }
        }        
        return flag;
    }
};