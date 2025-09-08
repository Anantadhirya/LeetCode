class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        bool valid;
        for(int a = 1, b; a < n; a++) {
            b = n-a;
            valid = 1;
            for(int x = a; x > 0; x /= 10) valid &= (x%10 != 0);
            for(int x = b; x > 0; x /= 10) valid &= (x%10 != 0);
            if(valid) return {a, b};
        }
        return {-1, -1};
    }
};