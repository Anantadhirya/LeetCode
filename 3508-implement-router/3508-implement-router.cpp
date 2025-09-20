class Router {
public:
    int n;
    queue<array<int, 3>> q;
    set<array<int, 3>> s;
    map<int, deque<int>> m;
    Router(int memoryLimit) {
        n = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        array<int, 3> a = {source, destination, timestamp};
        if(s.count(a)) return false;
        q.push(a);
        s.insert(a);
        m[destination].push_back(timestamp);
        if(q.size() > n) forwardPacket();
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()) return {};
        array<int, 3> a = q.front();
        m[a[1]].pop_front();
        s.erase(a);
        q.pop();
        return {a[0], a[1], a[2]};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        deque<int> &dq = m[destination];
        return upper_bound(dq.begin(), dq.end(), endTime) - lower_bound(dq.begin(), dq.end(), startTime);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */