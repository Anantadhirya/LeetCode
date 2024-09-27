class MyCalendarTwo {
public:
    set<pair<int, int>> s, s2;
    MyCalendarTwo() {
        ios_base::sync_with_stdio(false); cin.tie(0);
    }
    
    bool book(int start, int end) {
        auto it2 = s2.lower_bound({start, 0});
        if(it2 != s2.end() && it2->first < end) return 0;
        if(it2 != s2.begin() && start < (--it2)->second) return 0;
        
        auto it = s.lower_bound({start, 0});
        while(it != s.end() && it->first < end) {
            if(it->second < end) {
                s2.insert(*it);
                it = s.erase(it);
            } else {
                s2.insert({it->first, end});
                end = it->first;
            }
        }
        if(it != s.begin() && start < (--it)->second) {
            s2.insert({start, min(end, it->second)});
            start = min(end, it->second);
        }
        if(start < end) s.insert({start, end});
        return 1;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */