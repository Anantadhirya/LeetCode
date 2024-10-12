class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<int> v;
        for(const auto &i: intervals) {
            v.push_back(2*i[1]+2);
            v.push_back(2*i[0]+1);
        }
        sort(v.begin(), v.end());
        int ans = 0, tmp = 0;
        for(const auto &i: v) {
            cout << i << "\n";
            if(i&1) tmp++;
            else tmp--;
            ans = max(ans, tmp);
        }
        return ans;
    }
};