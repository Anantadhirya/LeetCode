const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int ans = 0, n = events.size();
        priority_queue<int> pq;
        sort(events.begin(), events.end());
        for(int d = 0, i = 0; !pq.empty() || i < n; ) {
            if(pq.empty()) d = events[i][0];
            while(i < n && events[i][0] <= d) pq.push(-events[i++][1]);
            if(!pq.empty()) {
                pq.pop();
                ans++;
            }
            d++;
            while(!pq.empty() && -pq.top() < d) pq.pop();
        }
        return ans;
    }
};