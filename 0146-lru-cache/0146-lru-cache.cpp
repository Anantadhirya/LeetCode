class LRUCache {
public:
    unordered_map<int, int> m, lst;
    queue<pair<int, int>> q;
    int n, i = 0, cnt = 0;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(!m.count(key) || m[key] == -1) return -1;
        lst[key] = ++i;
        q.push({key, i});
        return m[key];
    }
    
    void put(int key, int value) {
        if(!m.count(key) || m[key] == -1) cnt++;
        m[key] = value;
        lst[key] = ++i;
        q.push({key, i});
        while(cnt > n) {
            key = q.front().first;
            value = q.front().second;
            if(value == lst[key]) {
                cnt--;
                m[key] = -1;
            }
            q.pop();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */