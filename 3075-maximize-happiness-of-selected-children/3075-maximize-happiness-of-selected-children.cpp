class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long ans = 0;
        for(int i = 0; i < k; i++) {
            ans += max((long long)happiness[i] - i, 0LL);
        }
        return ans;
    }
};