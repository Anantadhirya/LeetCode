class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = n+1;
        for(int i = 0, d; i < n; i++) {
            if(words[i] == target) {
                d = abs(i - startIndex);
                ans = min(ans, min(d, n - d));
            }
        }
        return ans == n+1 ? -1 : ans;
    }
};