class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long mn = 0, mx = 0, tmp = 0;
        for(int i: differences) {
            tmp += i;
            mn = min(mn, tmp);
            mx = max(mx, tmp);
        }
        return max(0LL, (upper-lower) - (mx-mn) + 1);
    }
};