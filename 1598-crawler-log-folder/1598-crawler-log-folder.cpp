class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(const auto &s: logs) {
            if(s == "../") ans = max(ans-1, 0);
            else if(s == "./") continue;
            else ans++;
        }
        return ans;
    }
};