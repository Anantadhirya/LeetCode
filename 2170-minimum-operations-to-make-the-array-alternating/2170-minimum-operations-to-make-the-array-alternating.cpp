class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        map<int, int> cnt[2];
        pair<int, int> mx[2][2];
        mx[0][0] = mx[0][1] = mx[1][0] = mx[1][1] = {0, -1};
        for(int i = 0, c; i < n; i++) {
            cnt[i&1][nums[i]]++;
        }
        for(int p = 0; p <= 1; p++) {
            for(auto [i, c]: cnt[p]) {
                if(c > mx[p][1].first) {
                    mx[p][1] = {c, i};
                    if(mx[p][1] > mx[p][0]) swap(mx[p][0], mx[p][1]);
                }
            }
        }
        if(mx[0][0].second != mx[1][0].second) return n - mx[0][0].first - mx[1][0].first;
        return n - max(mx[0][0].first + mx[1][1].first, mx[0][1].first + mx[1][0].first);
    }
};