class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = nums.size();
        vector<pair<int, int>> v(n);
        vector<vector<int>> groups(1);
        for(int i = 0; i < n; i++) {
            v[i] = {nums[i], i};
        }
        sort(v.begin(), v.end());
        int mx = v[0].first, t = 0;
        for(int i = 0; i < n; i++) {
            if(v[i].first - mx > limit) {
                t++;
                groups.push_back({});
            }
            nums[v[i].second] = t;
            groups.back().push_back(v[i].first);
            mx = v[i].first;
        }
        vector<int> idx(t+1, 0);
        for(int i = 0; i < n; i++) {
            nums[i] = groups[nums[i]][idx[nums[i]]++];
        }
        return nums;
    }
};