class Solution {
public:
    bool prime(int x) {
        if(x == 1) return 0;
        for(int i = 2; i*i <= x; i++) {
            if(x % i == 0) return 0;
        }
        return 1;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int fi = -1, lst = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(prime(nums[i])) {
                if(fi == -1) fi = i;
                lst = i;
            }
        }
        return lst - fi;
    }
};