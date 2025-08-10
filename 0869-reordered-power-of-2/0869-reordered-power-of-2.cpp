class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> cnt(10, 0);
        vector<vector<int>> s;
        for(int i = 1; i <= 1e9; i <<= 1) {
            cnt.assign(10, 0);
            for(int j = i; j > 0; j /= 10) {
                cnt[j%10]++;
            }
            s.push_back(cnt);
        }
        cnt.assign(10, 0);
        for(int j = n; j > 0; j /= 10) {
            cnt[j%10]++;
        }
        for(const auto &i: s) {
            if(cnt == i) return 1;
        }
        return 0;
    }
};