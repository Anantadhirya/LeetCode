class CustomStack {
public:
    int n;
    int idx;
    vector<int> s, v;
    CustomStack(int maxSize) {
        n = maxSize;
        idx = 0;
        s.resize(n);
        v.resize(n);
    }
    
    void push(int x) {
        if(idx == n) return;
        s[idx] = x;
        v[idx] = 0;
        idx++;
    }
    
    int pop() {
        if(idx == 0) return -1;
        idx--;
        if(idx != 0) v[idx-1] += v[idx];
        return s[idx] + v[idx];
    }
    
    void increment(int k, int val) {
        if(idx == 0) return;
        v[min(k, idx)-1] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */