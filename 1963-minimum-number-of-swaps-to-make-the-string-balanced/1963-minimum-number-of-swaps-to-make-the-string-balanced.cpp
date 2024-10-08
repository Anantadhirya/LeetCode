class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0, ans = 0;
        for(auto &i: s) {
            if(i == '[') cnt++;
            else cnt--;
            if(cnt < 0) {
                ans++;
                cnt += 2;
            }
        }
        return ans;
    }
};