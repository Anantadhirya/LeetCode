class MinStack {
public:
    priority_queue<long long> pq;
    map<long long, int> cnt;
    stack<long long> s;
    MinStack() {
        ios_base::sync_with_stdio(false); cin.tie(0);
    }
    
    void push(int val) {
        pq.push(-(long long)val);
        cnt[val]++;
        s.push(val);
    }
    
    void pop() {
        cnt[s.top()]--;
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        while(!cnt[-pq.top()]) pq.pop();
        return -pq.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */