class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return arr;
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) {
            v[i] = {arr[i], i};
        }
        sort(v.begin(), v.end());
        int lst = v[0].first, tmp;
        v[0].first = 1;
        for(int i = 1; i < n; i++) {
            tmp = v[i].first;
            v[i].first = v[i-1].first + (v[i].first != lst);
            lst = tmp;
        }
        for(const auto &[val, idx]: v) {
            arr[idx] = val;
        }
        return arr;
    }
};