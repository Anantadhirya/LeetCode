class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0, n = pref.size();
        for(const auto &i: words) {
            if(i.size() < n) continue;
            ans++;
            for(int j = 0; j < n; j++) {
                if(pref[j] != i[j]) {
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};