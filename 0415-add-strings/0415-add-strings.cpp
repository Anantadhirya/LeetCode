class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int n = num1.size(), m = num2.size();
        int k = max(n, m), carry = 0;
        for(int i = 0; i < k || carry; i++) {
            ans.push_back(carry);
            if(i < n) ans.back() += num1[n-1-i] - '0';
            if(i < m) ans.back() += num2[m-1-i] - '0';
            carry = ans.back()/10;
            ans.back() = ans.back() % 10 + '0';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};