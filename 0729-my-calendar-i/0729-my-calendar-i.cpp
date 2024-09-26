class MyCalendar {
public:
    set<pair<int, int>> s;
    MyCalendar() {
        ios_base::sync_with_stdio(false); cin.tie(0);
    }
    
    bool book(int start, int end) {
        auto it = s.lower_bound({start, 0});
        if(it != s.end() && it->first < end) return 0;
        if(it != s.begin()) {
            it--;
            if(start < it->second) return 0;
        }
        s.insert({start, end});
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */