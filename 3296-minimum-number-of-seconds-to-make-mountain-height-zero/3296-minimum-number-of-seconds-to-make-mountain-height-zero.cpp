class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l = 0, r = (long long)workerTimes[0]*mountainHeight*(mountainHeight+1)/2, mid, ans = -1;
        long long tmp, x;
        auto check = [&](long long k) -> bool {
            tmp = 0;
            // w * (x * (x+1) / 2) <= k
            // x^2 + x <= 2k/w
            // x^2 + x - 2k/w <= 0
            // x <= (-1 + sqrt(1 + 8k/w)) / 2
            for(int &w: workerTimes) {
                x = (sqrt(1 + k*8/w) - 1) / 2;
                tmp += x;
                if(tmp >= mountainHeight) return 1;
            }
            return 0;
        };
        while(l <= r) {
            mid = (l+r)/2;
            if(check(mid)) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        return ans;
    }
};