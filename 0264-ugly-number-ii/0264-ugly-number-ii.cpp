class Solution {
public:
    int nthUglyNumber(int n) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<int> ans(n);
        int a, b, c;
        int aa, bb, cc;
        a = b = c = 0;
        ans[0] = 1;
        for(int i = 1; i < n; i++) {
            aa = ans[a]*2, bb = ans[b]*3, cc = ans[c]*5;
            ans[i] = min(aa, min(bb, cc));
            if(ans[i] == aa) a++;
            if(ans[i] == bb) b++;
            if(ans[i] == cc) c++;
        }
        return ans.back();
    }
};