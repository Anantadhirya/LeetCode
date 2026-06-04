class Solution {
public:
    int f(int x) {
        string s = to_string(x);
        int ret = 0;
        for(int i = s.size()-2; i >= 1; i--) {
            ret += (s[i-1] < s[i] && s[i] > s[i+1]);
            ret += (s[i-1] > s[i] && s[i] < s[i+1]);
        }
        return ret;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i = num1; i <= num2; i++) {
            ans += f(i);
        }
        return ans;
    }
};