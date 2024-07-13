class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = positions.size();
        vector<pair<int, int>> v;
        vector<int> ans, ret;
        for(int i = 0; i < n; i++) {
            v.push_back({positions[i], i});
        }
        sort(v.begin(), v.end());
        for(auto &[_, i]: v) {
            while(!ans.empty() && directions[ans.back()] == 'R' && directions[i] == 'L' && healths[i] != 0) {
                if(healths[ans.back()] == healths[i]) {
                    healths[ans.back()] = 0;
                    healths[i] = 0;
                    ans.pop_back();
                } else if(healths[ans.back()] < healths[i]) {
                    healths[ans.back()] = 0;
                    healths[i]--;
                    ans.pop_back();
                } else if(healths[ans.back()] > healths[i]) {
                    healths[ans.back()]--;
                    healths[i] = 0;
                    if(healths[ans.back()] == 0) ans.pop_back();
                }
            } 
            if(healths[i] > 0) ans.push_back(i);
        }
        for(int i = 0; i < n; i++) {
            if(healths[i] != 0) ret.push_back(healths[i]);
        }
        return ret;
    }
};