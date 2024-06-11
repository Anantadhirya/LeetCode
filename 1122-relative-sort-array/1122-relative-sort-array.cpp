class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> cnt;
        vector<int> ans;
        for(const int &i: arr1) {
            cnt[i]++;
        }
        for(const int &i: arr2) {
            for(int &j = cnt[i]; j--; ) {
                ans.push_back(i);
            }
        }
        for(const auto &i: cnt) {
            for(int j = 0; j < i.second; j++) {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};