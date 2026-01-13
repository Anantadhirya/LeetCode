#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        double l = 1e9, r = 0, mid, ans;
        double area, limit;
        for(const auto &i: squares) {
            l = min(l, (double)i[1]);
            r = max(r, (double)i[1]+i[2]);
            limit += (double)i[2]*i[2]/2.0;
        }
        while(r-l > 1e-5) {
            mid = (r+l)/2;
            area = 0;
            for(const auto &i: squares) {
                if(i[1] <= mid) area += (double)i[2]*min((double)i[2], mid-i[1]);
            }
            if(area >= limit) {
                ans = mid;
                r = mid;
            } else l = mid;
        }
        return ans;
    }
};