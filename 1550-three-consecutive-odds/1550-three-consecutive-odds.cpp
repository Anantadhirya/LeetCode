class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        for(int i = 2; i < n; i++) {
            if(arr[i]&arr[i-1]&arr[i-2]&1) return 1;
        }
        return 0;
    }
};