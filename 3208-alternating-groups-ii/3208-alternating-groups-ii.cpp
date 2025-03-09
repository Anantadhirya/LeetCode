class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int cnt = 0, ans = 0, n = colors.size();
        for(int i = 0; i+1 < k; i++) {
            cnt += (colors[i] == colors[i+1]);
        }
        for(int i = n-1; i >= 0; i--) {
            cnt += (colors[i] == colors[(i+1)%n]) - (colors[(i+k-1)%n] == colors[(i+k)%n]);
            ans += (cnt == 0);
        }
        return ans;
    }
};