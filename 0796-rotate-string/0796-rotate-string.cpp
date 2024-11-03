class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(goal.size() != n) return 0;
        for(int i = 0, valid; i < n; i++) {
            valid = 1;
            for(int j = 0; j < n; j++) {
                if(s[j] != goal[(i+j)%n]) {
                    valid = 0;
                    break;
                }
            }
            if(valid) return 1;
        }
        return 0;
    }
};