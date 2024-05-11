class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = quality.size();
        vector<pair<double, int>> v(n);
        
        for(int i = 0; i < n; i++) {
            v[i] = {1.0*wage[i]/quality[i], quality[i]};
        }
        sort(v.begin(), v.end());
        
        priority_queue<int> pq;
        int smQ = 0;
        double ans = 1/0.0;
        for(const auto &[r, q]: v) {
            pq.push(q);
            smQ += q;
            while(pq.size() > k) {
                smQ -= pq.top();
                pq.pop();
            }
            if(pq.size() == k) {
                ans = min(ans, r * smQ);
            }
        }
        return ans;
    }
};