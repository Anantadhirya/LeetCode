class RLEIterator {
public:
    vector<pair<int, int>> v;
    RLEIterator(vector<int>& encoding) {
        for(int i = encoding.size()-2; i >= 0; i -= 2) {
            v.push_back({encoding[i], encoding[i+1]});
        }
    }
    
    int next(int n) {
        int ans = -1, x;
        while(n > 0 && !v.empty()) {
            x = min(n, v.back().first);
            v.back().first -= x;
            n -= x;
            if(x > 0) ans = v.back().second;
            if(v.back().first == 0) v.pop_back();
        }
        return n == 0 ? ans : -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */