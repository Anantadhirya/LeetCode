class Solution {
public:
    bool check(vector<int> &nums, int l, int r) {
        vector<int> v;
        for(int i = l; i <= r; i++) {
            v.push_back(nums[i]);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i+1 < r-l+1; i++) {
            if(v[i+1] - v[i] != v[1] - v[0]) return 0;
        }
        return 1;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        int q = l.size();
        for(int i = 0; i < q; i++) {
            ans.push_back(check(nums, l[i], r[i]));
        }
        return ans;
    }
};