class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n > 0) {
            if(n % 3 == 1) n--;
            if(n % 3 != 0) return 0;
            n /= 3;
        }
        return 1;
    }
};