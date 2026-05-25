class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> suff(n, 0);
        suff[n-1] = (s[n-1] == '0');
        bool valid;
        for(int i = n-2; i >= 0; i--) {
            valid = (s[i] == '0') && ((i+minJump >= n ? 0 : suff[i+minJump]) - (i+maxJump+1 >= n ? 0 : suff[i+maxJump+1]) > 0);
            suff[i] = suff[i+1] + valid;
        }
        return suff[0] - suff[1] > 0;
    }
};