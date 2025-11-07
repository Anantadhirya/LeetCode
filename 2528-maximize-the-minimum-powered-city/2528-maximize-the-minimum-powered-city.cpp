const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    bool check(long long x, vector<int> &stations, int &r, int &k) {
        long long sm = 0, cnt = 0;
        int n = stations.size();
        vector<int> v(n, 0);
        for(int i = 0; i <= r; i++) {
            sm += stations[i];
        }
        for(int i = 0; i < n; i++) {
            sm -= v[i];
            if(sm < x) {
                cnt += x - sm;
                if(i+2*r+1 < n) v[i+2*r+1] += x - sm;
                sm += x - sm;
            }
            if(i+r+1 < n) sm += stations[i+r+1];
            if(i-r >= 0) sm -= stations[i-r];
        }
        return cnt <= k;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        long long L = 0, R = 1e11, mid, ans = 0;
        while(L <= R) {
            mid = (L+R)/2;
            if(check(mid, stations, r, k)) {
                ans = mid;
                L = mid + 1;
            } else R = mid - 1;
        }
        return ans;
    }
};