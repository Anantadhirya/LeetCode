class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int n = rungs.size();
        int ans = (rungs[0]-1)/dist;
        for(int i = 0; i+1 < n; i++) {
            ans += (rungs[i+1] - rungs[i] - 1)/dist;
        }
        return ans;
    }
};