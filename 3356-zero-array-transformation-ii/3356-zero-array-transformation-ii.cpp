class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size(), ans = -1, sm;
        vector<vector<pair<int, int>>> add(n+1);
        for(int i = 0; i < m; i++) {
            add[queries[i][0]].push_back({i, queries[i][2]});
            add[queries[i][1]+1].push_back({i, -queries[i][2]});
        }
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < add[i].size(); j++) {
                add[i][j].second += add[i][j-1].second;
            }
        }
        for(int l = 0, r = m, mid, valid; l <= r; ) {
            mid = (l + r)/2;
            sm = 0;
            valid = 1;
            for(int i = 0; i < n; i++) {
                auto it = lower_bound(add[i].begin(), add[i].end(), make_pair(mid, INT_MIN));
                if(it != add[i].begin()) sm += (--it)->second;
                if(sm < nums[i]) {
                    valid = 0;
                    break;
                }
            }
            if(valid) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }
};