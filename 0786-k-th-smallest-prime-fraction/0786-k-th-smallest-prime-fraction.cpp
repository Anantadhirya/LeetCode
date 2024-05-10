class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double, pair<int, int>>> v;
        int n = arr.size();
        vector<int> ans(2);
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                v.push_back({1.0*arr[i]/arr[j], {arr[i], arr[j]}});
            }
        }
        sort(v.begin(), v.end());
        ans[0] = v[k-1].second.first;
        ans[1] = v[k-1].second.second;
        return ans;
    }
};