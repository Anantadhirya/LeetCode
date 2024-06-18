class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(), m = worker.size();
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) {
            v[i] = {difficulty[i], profit[i]};
        }
        sort(v.begin(), v.end());
        sort(worker.begin(), worker.end());
        int ans = 0, p = 0;
        for(int i = 0, j = 0; i < m; i++) {
            while(j < n && v[j].first <= worker[i]) {
                p = max(p, v[j].second);
                j++;
            }
            ans += p;
        }
        return ans;
    }
};