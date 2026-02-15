class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        for(int i = a.size()-1, j = b.size()-1, carry = 0; i >= 0 || j >= 0 || carry; i--, j--) {
            ans.push_back(0);
            if(i >= 0) ans.back() += (a[i]-'0');
            if(j >= 0) ans.back() += (b[j]-'0');
            if(carry) ans.back() += carry;
            carry = ans.back()/2;
            ans.back() = ans.back()%2 + '0';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};