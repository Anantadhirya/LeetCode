class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        bitset<1000> vis;
        int ans = 0;
        for(int i = 0, x; i < n; i++) {
            if(digits[i] == 0) continue;
            for(int j = 0; j < n; j++) {
                if(j == i) continue;
                for(int k = 0; k < n; k++) {
                    if(digits[k] % 2 != 0) continue;
                    if(k == i || k == j) continue;
                    x = 100*digits[i] + 10*digits[j] + digits[k];
                    if(!vis[x]) {
                        ans++;
                        vis[x] = 1;
                    }
                }
            }
        }
        return ans;
    }
};