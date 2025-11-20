class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        for(auto &i: intervals) swap(i[0], i[1]);
        sort(intervals.begin(), intervals.end());
        vector<int> ans;
        int cnt;
        for(auto i: intervals) {
            swap(i[0], i[1]);
            cnt = 2 - min(2, (int)(ans.end() - lower_bound(ans.begin(), ans.end(), i[0])));
            if(cnt == 2) ans.push_back(i[1] - 1);
            if(cnt >= 1) {
                ans.push_back(i[1] - (ans.back() == i[1]));
                if(ans.size() >= 2 && ans.back() < ans[ans.size()-2]) swap(ans[ans.size()-2], ans.back());
            }
        }
        for(auto i: ans) cout << i << " ";
        cout << "\n";
        return (int)ans.size();
    }
};