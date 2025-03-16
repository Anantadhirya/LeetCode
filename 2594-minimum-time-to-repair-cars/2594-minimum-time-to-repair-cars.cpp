const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long ans = -1, l = 0, r = (long long)*min_element(ranks.begin(), ranks.end()) * cars * cars, mid, cnt;
        while(l <= r) {
            mid = (l+r)/2;
            cnt = 0;
            for(const int &i: ranks) {
                cnt += floor(sqrt((double)mid/i));
            }
            if(cnt >= cars) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }
};