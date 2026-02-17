class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for(int h = 0; h <= 11; h++) {
            for(int m = 0; m < 60; m++) {
                if(__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    ans.push_back(to_string(h) + ":" + "00");
                    ans.back()[ans.back().size()-2] = m/10 + '0';
                    ans.back()[ans.back().size()-1] = m%10 + '0';
                }
            }
        }
        return ans;
    }
};