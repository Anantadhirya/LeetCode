class Solution {
public:
    bool canChange(string start, string target) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = start.size();
        int l = 0, r = 0;
        for(int i = 0; i < n; i++) {
            if(target[i] == 'L') {
                if(r != 0) return false;
                l++;
            }
            if(start[i] == 'R') {
                if(l != 0) return false;
                r++;
            }
            if(start[i] == 'L') {
                if(l == 0) return false;
                l--;
            }
            if(target[i] == 'R') {
                if(r == 0) return false;
                r--;
            }
        }
        return l == 0 && r == 0;
    }
};