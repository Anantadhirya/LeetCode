class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;
        int n = word.size();
        int m = n - numFriends + 1;
        string ans = "";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(j >= ans.size() || ans[j] < word[i+j]) {
                    ans = word.substr(i, min(m, n-i));
                    break;
                }
                if(ans[j] != word[i+j]) break;
            }
        }
        return ans;
    }
};