class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = bloomDay.size();
        int l = 1, r = 1e9, mid;
        int tmp = 0, ans = -1;
        while(l <= r) {
            mid = (l+r)/2;
            tmp = 0;
            for(int i = 0, j = 0; i < n; i++) {
                if(bloomDay[i] <= mid) {
                    j++;
                } else j = 0;
                if(j >= k) {
                    j -= k;
                    tmp++;
                }
            }
            if(tmp >= m) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }
};