class Solution {
public:
    string oddString(vector<string>& words) {
        int m = words.size(), n = words[0].size();
        vector<vector<int>> diff(m, vector<int>(n-1, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n-1; j++) {
                diff[i][j] = words[i][j+1] - words[i][j];
            }
        }
        if(diff[0] != diff[1] && diff[0] != diff[2]) return words[0];
        for(int i = 1; i < m; i++) {
            if(diff[i] != diff[0]) return words[i];
        }
        return "";
    }
};