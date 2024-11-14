class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int l = 1, r = *max_element(quantities.begin(), quantities.end()), mid, ans = -1, cnt;
        while(l <= r) {
            mid = (l+r)/2;
            cnt = 0;
            for(const auto &i: quantities) {
                cnt += (i+mid-1)/mid;
            }
            if(cnt <= n) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }
};