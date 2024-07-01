class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = arr.size();
        for(int i = 2; i < n; i++) {
            if(arr[i]&arr[i-1]&arr[i-2]&1) return 1;
        }
        return 0;
    }
};