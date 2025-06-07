class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int cnt = 0, n = arr.size() - m;
        for(int i = 0; i < n; i++) {
            if(arr[i] != arr[i+m]) cnt = 0;
            else cnt++;

            if(cnt >= (k-1)*m) return 1;
        }
        return 0;
    }
};