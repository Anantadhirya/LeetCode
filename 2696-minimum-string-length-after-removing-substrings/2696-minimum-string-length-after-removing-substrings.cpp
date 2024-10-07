class Solution {
public:
    int minLength(string s) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<char> v;
        for(const auto &i: s) {
            if(!v.empty() && v.back() == 'A' && i == 'B') v.pop_back();
            else if(!v.empty() && v.back() == 'C' && i == 'D') v.pop_back();
            else v.push_back(i);
        }
        return v.size();
    }
};