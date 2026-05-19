class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v;
        vector<int> s;
        for(int i = 0; i < n; i++) {
            if(nums[i] <= i) v.emplace_back(i - nums[i], nums[i]);
        }
        sort(v.begin(), v.end());
        for(auto &[_, i]: v) {
            auto it = lower_bound(s.begin(), s.end(), i);
            if(it == s.end()) s.push_back(i);
            else *it = i;
        }
        return s.size();
    }
};