class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int tmp = INT_MAX;
        vector<vector<int>> ans;
        for(int i = 0; i+1 < arr.size(); i++) {
            if(arr[i+1] - arr[i] < tmp) {
                tmp = arr[i+1] - arr[i];
                ans.clear();
            }
            if(arr[i+1] - arr[i] == tmp) {
                ans.push_back({arr[i], arr[i+1]});
            }
        }
        return ans;
    }
};