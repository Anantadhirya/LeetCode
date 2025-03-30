class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size(), idx;
        vector<int> lst(26, -1), ans;
        for(int i = 0; i < n; i++) {
            lst[s[i]-'a'] = i;
        }
        idx = 0;
        ans.push_back(0);
        for(int i = 0; i < n; i++) {
            if(idx < i) ans.push_back(0);
            ans.back()++;
            idx = max(idx, lst[s[i]-'a']);
        }
        return ans;
    }
};