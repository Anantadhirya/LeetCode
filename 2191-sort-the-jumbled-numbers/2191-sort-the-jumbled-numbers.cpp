class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> v;
        vector<int> ans;
        int tmp;
        for(const auto &i: nums) {
            tmp = 0;
            for(int j = 1, x = i; x > 0; j *= 10, x /= 10) {
                tmp += j * mapping[x % 10];
            }
            if(i == 0) tmp = mapping[0];
            // cout << tmp << " " << i << "\n";
            v.push_back({tmp, v.size()});
        }
        sort(v.begin(), v.end());
        for(const auto &[_, i]: v) {
            ans.push_back(nums[i]);
        }
        return ans;
    }
};