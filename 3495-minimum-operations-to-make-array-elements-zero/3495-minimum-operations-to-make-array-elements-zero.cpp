class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0, tmp;
        for(const auto &i: queries) {
            tmp = 0;
            for(int j = 1; j <= i[1]; j *= 4) {
                tmp += i[1] - max(i[0]-1, j-1);
            }
            ans += (tmp+1)/2;
        }
        return ans;
    }
};