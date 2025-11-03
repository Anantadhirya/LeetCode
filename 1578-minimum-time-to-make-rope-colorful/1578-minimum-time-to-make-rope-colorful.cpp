class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int mx = 0, sm = 0, ans = 0;
        for(int i = 0; i < colors.size(); i++) {
            mx = max(mx, neededTime[i]);
            sm += neededTime[i];
            if(i+1 >= colors.size() || colors[i] != colors[i+1]) {
                ans += sm - mx;
                mx = sm = 0;
            }
        }
        return ans;
    }
};