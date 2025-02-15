class Solution {
public:
    bool partitionedSum(int num, int target) {
        if(num == target) return 1;
        if(num < 10) return 0;
        for(int i = 10; i < num; i *= 10) {
            if(partitionedSum(num%i, target - num/i)) return 1;
        }
        return 0;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(partitionedSum(i*i, i)) ans += i*i;
        }
        return ans;
    }
};