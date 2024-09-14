class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int lst = -1, cnt = 0;
        pair<int, int> ans = {0, 0};
        for(const int &i: nums) {
            if(lst != i) {
                lst = i;
                cnt = 0;
            }
            cnt++;
            ans = max(ans, {i, cnt});
        }
        return ans.second;
    }
};