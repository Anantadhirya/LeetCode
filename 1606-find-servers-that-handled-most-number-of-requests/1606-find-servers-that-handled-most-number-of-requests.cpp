class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> cnt(k, 0);
        set<int> free;
        priority_queue<pair<int, int>> pq;
        int n = arrival.size();
        for(int i = 0; i < k; i++) free.insert(i);
        for(int i = 0; i < n; i++) {
            while(!pq.empty() && -pq.top().first <= arrival[i]) {
                free.insert(pq.top().second);
                pq.pop();
            }
            if(free.empty()) continue;
            auto it = free.lower_bound(i%k);
            if(it == free.end()) it = free.begin();
            cnt[*it]++;
            pq.push({-(arrival[i]+load[i]), *it});
            free.erase(it);
        }
        vector<int> ans(1, 0);
        for(int i = 1; i < k; i++) {
            if(cnt[i] < cnt[ans.back()]) continue;
            if(cnt[i] > cnt[ans.back()]) ans.clear();
            ans.push_back(i);
        }
        return ans;
    }
};