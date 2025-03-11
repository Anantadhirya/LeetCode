class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size(), curr = 0;
        vector<int> ans;
        while(n > 0 || m > 0 || curr != 0) {
            curr += (n > 0 ? arr1[--n] : 0) + (m > 0 ? arr2[--m] : 0);
            if(abs(curr) % 2 == 1) {
                ans.push_back(1);
                curr--;
            } else ans.push_back(0);
            curr /= -2;
        }
        while(ans.back() == 0 && ans.size() > 1) ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};