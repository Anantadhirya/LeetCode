class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        string tmp;
        set<string> s;
        int ans = 0;
        for(auto &i: arr1) {
            tmp = to_string(i);
            while(!tmp.empty()) {
                s.insert(tmp);
                tmp.pop_back();
            }
        }
        for(auto &i: arr2) {
            tmp = to_string(i);
            while(!tmp.empty()) {
                if(s.count(tmp)) {
                    ans = max(ans, (int)tmp.size());
                    break;
                }
                tmp.pop_back();
            }
        }
        return ans;
    }
};