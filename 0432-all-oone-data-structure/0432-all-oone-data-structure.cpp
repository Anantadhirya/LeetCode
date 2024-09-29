class AllOne {
public:
    map<string, int> cnt;
    priority_queue<pair<int, string>> mx, mn;
    AllOne() {

    }

    void update(string key) {
        if(cnt[key] == 0) return;
        mx.push({cnt[key], key});
        mn.push({-cnt[key], key});
    }
    
    void inc(string key) {
        cnt[key]++;
        update(key);
    }
    
    void dec(string key) {
        cnt[key]--;
        update(key);
    }
    
    string getMaxKey() {
        while(!mx.empty()) {
            auto [c, k] = mx.top();
            if(cnt[k] != c) mx.pop();
            else break;
        }
        if(mx.empty()) return "";
        return mx.top().second;
    }
    
    string getMinKey() {
        while(!mn.empty()) {
            auto [c, k] = mn.top();
            if(-cnt[k] != c) mn.pop();
            else break;
        }
        if(mn.empty()) return "";
        return mn.top().second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */