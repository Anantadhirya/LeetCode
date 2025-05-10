const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sm1 = 0, sm2 = 0;
        int cnt1 = 0, cnt2 = 0;
        for(const int &i: nums1) sm1 += (i ? i : 1), cnt1 += (!i);
        for(const int &i: nums2) sm2 += (i ? i : 1), cnt2 += (!i);
        if(sm1 == sm2) return sm1;
        else if(sm1 > sm2 && cnt2) return sm1;
        else if(sm1 < sm2 && cnt1) return sm2;
        return -1;
    }
};