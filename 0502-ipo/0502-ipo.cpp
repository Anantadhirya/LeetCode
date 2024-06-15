class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<pair<int, int>> v;
        priority_queue<int> pq;
        int n = profits.size();
        for(int i = 0; i < n; i++) {
            v.push_back({capital[i], profits[i]});
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++) {
            while(!pq.empty() && k > 0 && w < v[i].first) {
                k--;
                w += pq.top();
                pq.pop();
            }
            if(v[i].first <= w) {
                pq.push(v[i].second);
            } else break;
        }
        while(!pq.empty() && k > 0) {
            k--;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};