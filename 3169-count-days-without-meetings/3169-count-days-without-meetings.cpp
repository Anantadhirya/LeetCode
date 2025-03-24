const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        map<int, int> cnt;
        cnt[1] = 0;
        cnt[days+1] = 0;
        for(auto &i: meetings) {
            cnt[i[0]]++;
            cnt[i[1]+1]--;
        }
        int ans = 0, tmp = 0, pref = 1;
        for(auto &[u, v]: cnt) {
            if(tmp == 0) {
                ans += u - pref;
            }
            tmp += v;
            pref = u;
        }
        return ans;
    }
};