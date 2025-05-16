class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        int k = words[0].size();
        vector<pair<int, int>> dp(n);
        string tmp;
        unordered_map<string, vector<pair<int, int>>> m[10];
        vector<int> id;
        vector<string> ans;
        for(int i = 0; i < n; i++) {
            tmp = words[i];
            tmp.pop_back();
            dp[i] = {1, -1};
            for(int j = words[i].size()-1; j >= 0; j--) {
                for(auto &[v, idx]: m[j][tmp]) {
                    if(idx == -1 || groups[idx] == groups[i]) continue;
                    dp[i] = max(dp[i], {v+1, idx});
                }
                if(j-1 >= 0) tmp[j-1] = words[i][j];
            }
            tmp = words[i];
            tmp.pop_back();
            for(int j = words[i].size()-1; j >= 0; j--) {
                pair<int, int> val = {dp[i].first, i};
                auto &vec = m[j][tmp];
                if(vec.size() == 0) vec.assign(2, {-1, -1});
                if(vec[0].second == -1 || groups[i] == groups[vec[0].second]) vec[0] = max(vec[0], val);
                else if(vec[1].second == -1 || groups[i] == groups[vec[1].second]) vec[1] = max(vec[1], val);
                else if(val > vec[0]) vec[1] = max(vec[1], vec[0]), vec[0] = val;
                else if(val > vec[1]) vec[0] = max(vec[0], vec[1]), vec[1] = val;
                if(j-1 >= 0) tmp[j-1] = words[i][j];
            }
        }
        id.push_back(0);
        for(int i = 0; i < n; i++) {
            if(dp[i].first >= dp[id[0]].first) id[0] = i;
        }
        while(id.back() != -1) id.push_back(dp[id.back()].second);
        for(int i = id.size()-2; i >= 0; i--) {
            ans.push_back(words[id[i]]);
        }
        return ans;
    }
};