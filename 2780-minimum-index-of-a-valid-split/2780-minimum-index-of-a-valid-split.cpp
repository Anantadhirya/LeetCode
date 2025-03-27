const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int x = 0, mx = 0, n = nums.size();
        for(const int &i: nums) {
            cnt[i]++;
        }
        for(const auto &[i, c]: cnt) {
            if(c > mx) mx = c, x = i;
        }
        for(int i = 0, l = 0, r; i < n - 1; i++) {
            l += (nums[i] == x);
            r = mx - l;
            if(l*2 > i+1 && r*2 > n-1-i) return i;
        }
        return -1;
    }
};