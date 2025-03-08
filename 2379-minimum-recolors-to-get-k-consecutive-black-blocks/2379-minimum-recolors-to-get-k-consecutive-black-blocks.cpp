class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt = 0, ans, n = blocks.size();
        for(int i = 0; i < k; i++) {
            cnt += (blocks[i] == 'W');
        }
        ans = cnt;
        for(int i = k; i < n; i++) {
            cnt += (blocks[i] == 'W') - (blocks[i-k] == 'W');
            ans = min(ans, cnt);
        }
        return ans;
    }
};