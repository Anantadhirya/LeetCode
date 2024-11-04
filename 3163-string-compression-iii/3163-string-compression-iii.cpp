class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        vector<pair<char, int>> v;
        for(auto &i: word) {
            if(v.empty() || i != v.back().first || v.back().second == 9) v.push_back({i, 1});
            else v.back().second++;
        }
        for(auto &[a, b]: v) {
            ans += to_string(b);
            ans.push_back(a);
        }
        return ans;
    }
};