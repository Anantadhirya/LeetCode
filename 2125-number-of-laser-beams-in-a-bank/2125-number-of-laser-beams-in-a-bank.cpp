class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, cnt, pref = 0;
        for(auto i: bank) {
            cnt = 0;
            for(auto j: i) {
                cnt += (j == '1');
            }
            if(cnt != 0) {
                ans += cnt * pref;
                pref = cnt;
            }
        }
        return ans;
    }
};