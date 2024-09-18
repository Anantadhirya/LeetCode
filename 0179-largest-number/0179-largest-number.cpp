class Solution {
public:
    string largestNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = nums.size();
        vector<string> v(n);
        for(int i = 0; i < n; i++) {
            v[i] = to_string(nums[i]);
        }
        sort(v.begin(), v.end(), [](const string &a, const string &b) {
            return (a + b) < (b + a);
        });
        if(v.back() == "0") return "0";
        string ans = "";
        for(int i = n-1; i >= 0; i--) {
            ans += v[i];
        }
        return ans;
    }
};