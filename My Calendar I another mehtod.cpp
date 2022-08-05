class MyCalendar{
public:
    map<int, int> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int sum=0;
        for(auto it=mp.begin(); it!=mp.end(); it++) {
            sum += it->second;
            if(sum>1){
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};