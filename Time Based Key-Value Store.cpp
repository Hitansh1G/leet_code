class TimeMap {
public:
    unordered_map<string, vector<pair<string,int>>> ump;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ump[key].push_back({value,timestamp});
    }
    
    int bs(vector <pair<string,int>> &v, int t){
        int low = 0;
        int high = v.size();
        
        while(high>low){
            int mid = (low+high)/2;
            if(v[mid].second >= t) high = mid;
            else low = mid + 1;
        }
        if(low < high && v[low].second < t) {
           low++;
        }
        return low;
    }
    string get(string key, int timestamp) {
        string emp;
        if(ump.find(key) == ump.end()) return emp;
        
        int f = bs(ump[key],timestamp);
        // cout << f <<endl;
        if(f==ump[key].size()) f--;
        else if(ump[key][f].second > timestamp) f--;
        if(f==-1)return emp;
        return ump[key][f].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */