class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(i%k == 0) ans.push_back("");
            ans.back() += s[i];
        }
        while(ans.back().size() < k) ans.back() += fill;
        return ans;
    }
};