const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return NULL; }();

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> mx(90, -1);
        int ans = -1, sm;
        for(const int &i: nums) {
            sm = 0;
            for(int j = i; j > 0; j /= 10) {
                sm += j%10;
            }
            if(mx[sm] != -1) ans = max(ans, mx[sm] + i);
            mx[sm] = max(mx[sm], i);
        }
        return ans;
    }
};