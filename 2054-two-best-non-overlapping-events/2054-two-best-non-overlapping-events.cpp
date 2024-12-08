class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        priority_queue<pair<int, int>> pq;
        int mx = 0, ans = 0;
        sort(events.begin(), events.end());
        for(const auto &i: events) {
            while(!pq.empty() && -pq.top().first < i[0]) {
                mx = max(mx, pq.top().second);
                pq.pop();
            }
            pq.push({-i[1], i[2]});
            ans = max(ans, i[2] + mx);
        }
        return ans;
    }
};