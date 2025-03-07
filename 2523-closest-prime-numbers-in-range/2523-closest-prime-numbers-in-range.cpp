class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        const int MX = 1e6 + 5;
        bitset<MX> np;
        int lst = -1;
        vector<int> ans(2, -1);
        for(int i = 2; i <= right; i++) {
            if(np[i]) continue;
            if(left <= i) {
                if(lst != -1) {
                    if(ans[0] == -1 || i - lst < ans[1] - ans[0]) ans = {lst, i};
                }
                lst = i; 
            }
            if(i > 1e3) continue;
            for(int j = i*i; j <= right; j += i) {
                np[j] = 1;
            }
        }
        return ans;
    }
};