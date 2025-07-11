class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<int> cnt(n, 0);
        pair<int,int> ans = {-1, -1};
        priority_queue<pair<long long, long long>> pq, pq2;
        for(int i = 0; i < n; i++) {
            pq2.push({-i, 0});
        }
        sort(meetings.begin(), meetings.end());
        for(auto &i: meetings) {
            while((!pq.empty() && -pq.top().first <= i[0]) || pq2.empty()) {
                pq2.push({pq.top().second, -pq.top().first});
                pq.pop();
            }
            cnt[-pq2.top().first]++;
            pq.push({-(max(pq2.top().second, (long long)i[0]) + (long long)i[1] - i[0]), pq2.top().first});
            pq2.pop();
        }
        for(int i = 0; i < n; i++) {
            ans = max(ans, {cnt[i], -i});
        }
        return -ans.second;
    }
};