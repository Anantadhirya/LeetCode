class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        set<vector<int>> s;
        unordered_map<int, bool> cnt;
        vector<int> tmp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                tmp = {-nums[i]-nums[j], nums[i], nums[j]};
                if(cnt[tmp[0]]) {
                    sort(tmp.begin(), tmp.end());
                    s.insert(tmp);
                }
            }
            cnt[nums[i]] = 1;
        }
        vector<vector<int>> ret(s.begin(), s.end());
        return ret;
    }
};