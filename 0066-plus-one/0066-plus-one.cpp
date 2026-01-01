class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1, n = digits.size();
        for(int i = n-1; i >= 0; i--) {
            digits[i] += carry;
            carry = digits[i]/10;
            digits[i] %= 10;
            if(carry == 0) break;
        }
        if(carry > 0) digits.insert(digits.begin(), 1);
        return digits;
    }
};