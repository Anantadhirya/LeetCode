class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> dp(n+1, m);
        for(int i = n-1; i >= 0; i--) {
            dp[i] = dp[i+1] - (dp[i+1]-1 >= 0 && word1[i] == word2[dp[i+1]-1]);
        }
        vector<int> ans;
        int missmatch = 0;
        int j = 0;
        for(int i = 0; i < n && j < m; i++) {
            if(word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } else {
                if(!missmatch && dp[i+1] <= j+1) {
                    ans.push_back(i);
                    missmatch++;
                    j++;
                }
            }
        }
        return j == m ? ans : vector<int>(0);
    }
};