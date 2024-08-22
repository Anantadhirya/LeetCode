class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        for(long long i = 1; i <= num; i <<= 1) {
            if(num&i) continue;
            ans += i;
        }
        return ans;
    }
};