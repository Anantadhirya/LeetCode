class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size(), idx, cnt;
        string ans(n, '0');
        vector<int> valid(n, 1);
        for(const string &s: nums) {
            cnt = 0;
            idx = -1;
            for(int i = 0; i < n; i++) {
                if(s[i] == '1') cnt++, idx = i;
            }
            if(cnt == 1) valid[idx] = 0;
        }
        for(int i = 0; i < n; i++) {
            if(valid[i]) {
                ans[i] = '1';
                break;
            }
        }
        return ans;
    }
};