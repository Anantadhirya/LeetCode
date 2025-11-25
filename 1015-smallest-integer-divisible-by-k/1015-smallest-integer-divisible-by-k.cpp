class Solution {
public:
    int smallestRepunitDivByK(int k) {
        vector<bool> vis(k, 0);
        int x = 1 % k, ans = 1;
        while(x != 0) {
            if(vis[x]) return -1;
            vis[x] = 1;
            x = (10*x + 1) % k;
            ans++;
        }
        return ans;
    }
};