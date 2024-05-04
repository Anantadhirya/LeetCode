class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mn = INT_MAX, mx = INT_MIN;
        if(!nums1.empty()) {
            mn = min(mn, nums1[0]);
            mx = max(mx, nums1.back());
        }
        if(!nums2.empty()) {
            mn = min(mn, nums2[0]);
            mx = max(mx, nums2.back());
        }
        int cnt1, cnt2, ansl, ansr;
        int sz = nums1.size() + nums2.size();
        int medl = (sz+1)/2, medr = medl + (sz%2==0);
        for(int l = mn, r = mx, mid; l <= r; ) {
            mid = l + r >> 1;
            cnt1 = upper_bound(nums1.begin(), nums1.end(), mid) - nums1.begin();
            cnt2 = upper_bound(nums2.begin(), nums2.end(), mid) - nums2.begin();
            if(cnt1 + cnt2 >= medl) {
                ansl = mid;
                r = mid-1;
            } else l = mid+1;
        }
        for(int l = mn, r = mx, mid; l <= r; ) {
            mid = l + r >> 1;
            cnt1 = upper_bound(nums1.begin(), nums1.end(), mid) - nums1.begin();
            cnt2 = upper_bound(nums2.begin(), nums2.end(), mid) - nums2.begin();
            if(cnt1 + cnt2 >= medr) {
                ansr = mid;
                r = mid-1;
            } else l = mid+1;
        }
        return (ansl+ansr)/2.0;
    }
};