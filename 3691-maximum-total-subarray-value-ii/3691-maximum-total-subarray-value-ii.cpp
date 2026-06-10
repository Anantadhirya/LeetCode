class Solution {
public:
    int f(int l, int r, vector<int> &lg, vector<vector<pair<int, int>>> &st) {
        int x = lg[r-l+1];
        int idx = r - (1<<x) + 1;
        int mn = min(st[l][x].first, st[idx][x].first);
        int mx = max(st[l][x].second, st[idx][x].second);
        return mx - mn;
    }
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int m = log2(n)+2;
        vector<int> lg(n+1, 0);
        for(int i = 2; i <= n; i++) {
            lg[i] = lg[i/2] + 1;
        }
        vector<vector<pair<int, int>>> st(n, vector<pair<int, int>>(m));
        for(int i = 0; i < n; i++) {
            st[i][0] = {nums[i], nums[i]};
        }
        for(int j = 1; j < m; j++) {
            for(int i = 0, idx; i < n; i++) {
                st[i][j] = st[i][j-1];
                idx = i + (1<<(j-1));
                if(idx < n) {
                    st[i][j].first = min(st[i][j].first, st[idx][j-1].first);
                    st[i][j].second = max(st[i][j].second, st[idx][j-1].second);
                }
            }
        }

        long long ans = 0;
        array<int, 3> tmp;
        priority_queue<array<int, 3>> pq;
        for(int i = 0; i < n; i++) {
            pq.push({f(i, n-1, lg, st), i, n-1});
        }
        while(k--) {
            tmp = pq.top();
            pq.pop();
            ans += (long long)tmp[0];
            if(tmp[1] <= tmp[2]-1) pq.push({f(tmp[1], tmp[2]-1, lg, st), tmp[1], tmp[2]-1});
        }
        return ans;
    }
};