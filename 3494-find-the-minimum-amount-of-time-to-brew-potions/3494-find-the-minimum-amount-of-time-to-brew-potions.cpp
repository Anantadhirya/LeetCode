const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        long long ans = 0, x;
        vector<long long> lst(n, 0);
        for(int j = 0; j < m; j++) {
            ans = lst[0];
            for(int i = 0; i < n; i++) {
                ans = max(lst[i], ans) + (long long)skill[i] * mana[j];
            }
            x = ans;
            for(int i = n-1; i >= 0; i--) {
                lst[i] = x;
                x -= (long long)skill[i] * mana[j];
            }
        }
        return ans;
    }
};