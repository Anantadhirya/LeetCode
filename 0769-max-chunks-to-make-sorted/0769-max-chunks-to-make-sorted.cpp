class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i = 0, j = 0; i < n; i++) {
            j = max(j, arr[i]);
            if(i == j) ans++;
        }
        return ans;
    }
};