class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n&1) return 0;
        int open = 0;
        vector<int> unlocked;
        for(int i = 0; i < n; i++) {
            if(locked[i] == '1') {
                if(s[i] == ')') {
                    if(open) open--;
                    else {
                        if(unlocked.empty()) return 0;
                        s[unlocked.back()] = '(';
                        locked[unlocked.back()] = '1';
                        unlocked.pop_back();
                    }
                } else open++;
            } else {
                unlocked.push_back(i);
            }
        }
        int close = 0, unlocked_cnt = 0;
        for(int i = n-1; i >= 0; i--) {
            if(locked[i] == '1') {
                if(s[i] == ')') close++;
                else {
                    if(close) close--;
                    else if(unlocked_cnt) unlocked_cnt--;
                    else return 0;
                }
            } else unlocked_cnt++;
        }
        return 1;
    }
};