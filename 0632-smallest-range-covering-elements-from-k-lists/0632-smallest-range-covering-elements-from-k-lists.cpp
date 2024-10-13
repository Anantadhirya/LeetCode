class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        set<pair<int, int>> s;
        pair<int, int> ans = {INT_MAX, 0};
        vector<int> idx(k, 0);
        int cur;
        for(int i = 0; i < k; i++) {
            s.insert({nums[i][0], i});
        }
        while(1) {
            ans = min(ans, {(--s.end())->first - s.begin()->first, s.begin()->first});
            cur = s.begin()->second;
            s.erase(s.begin());
            if(idx[cur] + 1 < nums[cur].size()) s.insert({nums[cur][++idx[cur]], cur});
            else break;
        }
        return {ans.second, ans.second + ans.first};
    }
};