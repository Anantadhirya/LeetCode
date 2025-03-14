const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int ans = 0;
        long long cnt;
        for(int l = 1, r = *max_element(candies.begin(), candies.end()), mid; l <= r; ) {
            mid = (l+r)/2;
            cnt = 0;
            for(const int &i: candies) {
                cnt += i/mid;
            }
            if(cnt >= k) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        return ans;
    }
};