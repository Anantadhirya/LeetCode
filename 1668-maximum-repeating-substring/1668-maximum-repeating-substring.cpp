class Solution {
public:
    int maxRepeating(string seq, string w) {
        int n = seq.size();
        int m = w.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; i+j < n; j++) {
                if(seq[i+j] != w[j%m]) break;
                ans = max(ans, (j+1)/m);
            }
        }
        return ans;
    }
};