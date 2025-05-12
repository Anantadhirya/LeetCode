class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> ans;
        for(int i = 0; i < n; i++) {
            if(digits[i]&1) continue;
            for(int j = 0; j < n; j++) {
                if(digits[j] == 0 || j == i) continue;
                for(int k = 0; k < n; k++) {
                    if(k == i || k == j) continue;
                    ans.insert(digits[j] * 100 + digits[k] * 10 + digits[i]);
                }
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};