class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int mx = 0, ans = 0, cur;
        for(const auto &i: rectangles) {
            cur = min(i[0], i[1]);
            if(cur == mx) ans++;
            else if(cur > mx) mx = cur, ans = 1;
        }
        return ans;
    }
};