const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    bool checkValidCuts(int k, vector<vector<int>>& rectangles) {
        vector<int> start[2], end[2];
        int n = rectangles.size(), cnt, ans;
        for(const auto &i: rectangles) {
            start[0].push_back(i[0]);
            start[1].push_back(i[1]);
            end[0].push_back(i[2]);
            end[1].push_back(i[3]);
        }
        for(int p = 0; p < 2; p++) {
            sort(start[p].begin(), start[p].end());
            sort(end[p].begin(), end[p].end());
            cnt = ans = 0;
            for(int i = 0, j = 0; i < n; i++) {
                cnt++;
                if(i != 0 && start[p][i] == start[p][i-1]) continue;
                while(j < n && end[p][j] <= start[p][i]) cnt--, j++;
                if(cnt == 1) ans++;
                if(ans >= 3) return 1;
            }
        }
        return 0;
    }
};