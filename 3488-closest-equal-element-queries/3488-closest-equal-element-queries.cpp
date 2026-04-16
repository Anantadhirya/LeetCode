class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, int> lst;
        vector<int> ans(n, INT_MAX);
        for(int i = 0; i < n; i++) lst[nums[i]] = i;
        for(int i = 0, j, d; i < n; i++) {
            j = lst[nums[i]];
            if(j == i) continue;
            d = abs(i-j);
            d = min(d, n-d);
            ans[i] = min(ans[i], d);
            ans[j] = min(ans[j], d);
            lst[nums[i]] = i;
        }
        for(int &i: queries) {
            i = ans[i] == INT_MAX ? -1 : ans[i];
        }
        return queries;
    }
};