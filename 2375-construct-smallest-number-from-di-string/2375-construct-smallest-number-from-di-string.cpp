class Solution {
public:
    string smallestNumber(string pattern) {
        string ans = "1";
        char c = '2';
        for(const auto &i: pattern) {
            if(i == 'I') ans += c++;
            else if(i == 'D') {
                c++;
                for(int j = ans.size()-1; j >= 0 && pattern[j] == 'D'; j--) {
                    ans[j]++;
                }
                ans += ans.back()-1;
            }
        }
        return ans;
    }
};