class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        map<int, queue<int>> nxt;
        map<int, bool> full;
        priority_queue<pair<int, int>> pq;
        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++) {
            if(rains[i] == 0) continue;
            nxt[rains[i]].push(i);
        }
        for(int i = 0; i < n; i++) {
            if(rains[i] != 0) {
                if(full[rains[i]]) return {};
                full[rains[i]] = 1;
                nxt[rains[i]].pop();
                if(!nxt[rains[i]].empty()) pq.push({-nxt[rains[i]].front(), rains[i]});
            } else {
                while(!pq.empty() && !full[pq.top().second]) pq.pop();
                if(pq.empty()) {
                    ans[i] = 1;
                    continue;
                }
                ans[i] = pq.top().second;
                full[pq.top().second] = 0;
                pq.pop();
            }
        }
        return ans;
    }
};