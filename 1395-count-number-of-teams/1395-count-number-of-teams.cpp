class Solution {
public:
    void update(int x, int &mx, vector<int> &ft) {
        for(int i = x; i < mx; i += i&-i) {
            ft[i]++;
        }
    }
    int query(int x, vector<int> &ft) {
        int ret = 0;
        for(int i = x; i > 0; i -= i&-i) {
            ret += ft[i];
        }
        return ret;
    }
    int numTeams(vector<int>& rating) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = rating.size();
        int mx = *max_element(rating.begin(), rating.end()) + 1;
        vector<int> ft(mx, 0);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(rating[i] < rating[j]) {
                    ans += query(rating[i]-1, ft);
                }
                if(rating[i] > rating[j]) {
                    ans += i - query(rating[i], ft);
                }
            }
            update(rating[i], mx, ft);
        }
        return ans;
    }
};