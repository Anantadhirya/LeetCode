class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = times.size();
        priority_queue<pair<int, int>> used;
        priority_queue<int> pq;
        int counter = 0, chair;
        vector<array<int, 3>> v(n);
        for(int i = 0; i < n; i++) {
            v[i] = {times[i][0], times[i][1], i};
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++) {
            while(!used.empty() && -used.top().first <= v[i][0]) {
                pq.push(-used.top().second);
                used.pop();
            }
            if(pq.empty()) pq.push(counter--);
            chair = -pq.top();
            if(v[i][2] == targetFriend) return chair;
            pq.pop();
            used.push({-v[i][1], chair});
        }
        return -1;
    }
};