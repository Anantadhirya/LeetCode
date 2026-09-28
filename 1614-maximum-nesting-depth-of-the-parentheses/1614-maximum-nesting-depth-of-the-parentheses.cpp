class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, tmp = 0;
        for(const char &i: s) {
            if(i == '(') tmp++;
            else if(i == ')') tmp--;
            ans = max(ans, tmp);
        }
        return ans;
    }
};