class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> cnt(k, 0);
        for(const auto &i: arr) {
            cnt[(i%k + k) % k]++;
        }
        if(cnt[0] % 2 == 1) return 0;
        for(int i = 1; i < k; i++) {
            if(cnt[i] != cnt[k-i]) return 0;
        }
        return 1;
    }
};