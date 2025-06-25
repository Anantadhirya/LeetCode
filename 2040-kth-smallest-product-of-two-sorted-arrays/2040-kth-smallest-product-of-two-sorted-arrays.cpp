const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        const long long inf = 1e10;
        long long l = -inf, r = inf, mid, ans, cnt;
        int ll, rr, mid2, cnt2, m = nums2.size();
        while(l <= r) {
            mid = (l+r)/2;
            cnt = 0;
            for(const int &i: nums1) {
                ll = 0;
                rr = m-1;
                cnt2 = 0;
                while(ll <= rr) {
                    mid2 = (ll+rr)/2;
                    if((long long)i * nums2[mid2] <= mid) {
                        if(i >= 0) cnt2 = mid2 + 1, ll = mid2 + 1;
                        else cnt2 = m - mid2, rr = mid2 - 1;
                    } else {
                        if(i >= 0) rr = mid2 - 1;
                        else ll = mid2 + 1;
                    }
                }
                cnt += cnt2;
            }
            if(cnt >= k) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }
};