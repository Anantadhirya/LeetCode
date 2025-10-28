const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sm = 0, ans = 0, tmp = 0;
        for(auto i: nums) {
            sm += i;
        }
        for(auto i: nums) {
            tmp += i;
            if(i != 0) continue;
            if(tmp * 2 == sm) ans += 2;
            if(abs(tmp * 2 - sm) == 1) ans += 1;
        }
        return ans;
    }
};