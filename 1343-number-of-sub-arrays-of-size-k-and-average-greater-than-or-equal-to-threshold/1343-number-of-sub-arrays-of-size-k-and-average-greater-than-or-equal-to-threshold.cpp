class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        for(int i = 1; i < n; i++) {
            arr[i] += arr[i-1];
        }
        int ans = 0;
        for(int i = 0; i+k-1 < n; i++) {
            if(arr[i+k-1] - (i-1 >= 0 ? arr[i-1] : 0) >= threshold*k) ans++;
        }
        return ans;
    }
};