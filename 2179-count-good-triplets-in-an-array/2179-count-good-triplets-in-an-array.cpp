const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    void update(int pos, int &n, vector<int> &ft) {
        for(int i = pos+1; i <= n; i += i&-i) {
            ft[i-1]++;
        }
    }
    int query(int pos, vector<int> &ft) {
        int ret = 0;
        for(int i = pos+1; i > 0; i -= i&-i) {
            ret += ft[i-1];
        }
        return ret;
    }
    int query(int l, int r, vector<int> &ft) {
        return query(r, ft) - query(l-1, ft);
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n), ft(n, 0);
        long long l, r, ans = 0;
        for(int i = 0; i < n; i++) {
            pos[nums2[i]] = i;
        }
        for(int i = 0; i < n; i++) {
            nums1[i] = pos[nums1[i]];
        }
        for(int i = 0; i < n; i++) {
            pos[nums1[i]] = i;
        }
        for(int i = 0; i < n; i++) {
            l = query(0, pos[i]-1, ft);
            r = (n-1-pos[i]) - query(pos[i]+1, n-1, ft);
            ans += l * r;
            update(pos[i], n, ft);
        }
        return ans;
    }
};