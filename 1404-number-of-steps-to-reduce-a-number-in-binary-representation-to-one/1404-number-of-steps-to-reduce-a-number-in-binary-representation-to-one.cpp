class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        while(s.size() > 1) {
            if(s.back() == '0') {
                s.pop_back();
                ans++;
            } else {
                ans++;
                while(!s.empty() && s.back() == '1') {
                    s.pop_back();
                    ans++;
                }
                if(!s.empty()) s.back() = '1';
            }
        }
        return ans;
    }
};