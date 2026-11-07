class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<array<long long, 3>> pq;
        priority_queue<array<long long, 2>> free;
        int n = tasks.size();
        vector<int> ans(n);
        for(int i = servers.size()-1; i >= 0; i--) {
            free.push({-servers[i], -i});
        }
        for(long long i = 0, t = 0; i < n; i++) {
            t = max(t, i);
            while(free.empty() || (!pq.empty() && -pq.top()[0] <= t)) {
                t = max(t, -pq.top()[0]);
                free.push({pq.top()[1], pq.top()[2]});
                pq.pop();
            }
            ans[i] = -free.top()[1];
            pq.push({-(t + tasks[i]), free.top()[0], free.top()[1]});
            free.pop();
        }
        return ans;
    }
};