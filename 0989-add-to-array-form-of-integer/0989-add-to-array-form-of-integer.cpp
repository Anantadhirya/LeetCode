class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        for(int i = num.size()-1, carry = 0; i >= 0 || k > 0 || carry > 0; i--, k /= 10) {
            ans.push_back((i >= 0 ? num[i] : 0) + k%10 + carry);
            carry = ans.back()/10;
            ans.back() %= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};