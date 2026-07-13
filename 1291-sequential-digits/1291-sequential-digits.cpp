class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s;
        int tmp;
        vector<int> ans;
        for(int len = 1; len <= 9; len++) {
            for(int start = 1; start + len - 1 <= 9; start++) {
                for(int i = 0; i < len; i++) {
                    s[i] = '0' + start + i;
                }
                tmp = stoi(s);
                if(low <= tmp && tmp <= high) {
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};