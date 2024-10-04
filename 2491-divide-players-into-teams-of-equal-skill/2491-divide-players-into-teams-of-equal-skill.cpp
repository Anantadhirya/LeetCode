class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = skill.size();
        sort(skill.begin(), skill.end());
        int sm = skill[0] + skill.back();
        long long ans = 0;
        for(int i = 0; i < n-i-1; i++) {
            if(skill[i] + skill[n-i-1] != sm) return -1;
            ans += (long long)skill[i] * skill[n-i-1];
        }
        return ans;
    }
};