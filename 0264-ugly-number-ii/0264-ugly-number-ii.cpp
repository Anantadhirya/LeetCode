class Solution {
public:
    int nthUglyNumber(int n) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        priority_queue<long long> pq;
        unordered_map<long long, bool> vis;
        pq.push(-1);
        for(int cnt = 1; cnt < n; cnt++) {
            while(vis[pq.top()]) pq.pop();
            vis[pq.top()] = 1;
            pq.push(pq.top()*2);
            pq.push(pq.top()*3);
            pq.push(pq.top()*5);
            pq.pop();
        }
        while(vis[pq.top()]) pq.pop();
        vis[pq.top()] = 1;
        return -pq.top();
    }
};