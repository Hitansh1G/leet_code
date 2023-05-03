class MyCalendarThree {
    public:
    map<int,int> mp; //time, sum
    MyCalendarThree() {

    }

    int book(int start, int end) {
        mp[start]++; //add one new event
        mp[end]--; //the event ends

        int res=0;
        int sum=0;
        for(auto& [time,diff] : mp){
            sum+=diff;
            res = std::max(res,sum);
        }

        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */