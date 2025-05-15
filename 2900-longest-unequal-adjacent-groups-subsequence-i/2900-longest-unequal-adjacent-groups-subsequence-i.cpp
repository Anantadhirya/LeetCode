class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans(1, words[0]);
        bool p = groups[0];
        int n = words.size();
        for(int i = 1; i < n; i++) {
            if(groups[i] != p) {
                p = groups[i];
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};