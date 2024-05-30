class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), tmp, ans = 0;
        unordered_map<int, int> cnt[n];
        for(int i = 0; i < n; i++) {
            tmp = 0;
            for(int j = i; j >= 0; j--) {
                tmp ^= arr[j];
                cnt[i][tmp]++;
                if(j != 0) ans += cnt[j-1][tmp];
            }
        }
        return ans;
    }
};