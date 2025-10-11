class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int mod = 0;
        vector<vector<int>> mn(3);
        string ans;
        for(const int &i: digits) {
            mod = (mod+i)%3;
            mn[i%3].push_back(i);
            for(int j = mn[i%3].size()-1; j-1 >= 0; j--) {
                if(mn[i%3][j-1] > mn[i%3][j]) swap(mn[i%3][j-1], mn[i%3][j]);
            }
        }
        if(mod != 0) {
            if(!mn[mod].empty()) {
                digits.erase(find(digits.begin(), digits.end(), mn[mod][0]));
            } else if(mn[2*mod%3].size() >= 2) {
                mod = 2*mod % 3;
                digits.erase(find(digits.begin(), digits.end(), mn[mod][0]));
                digits.erase(find(digits.begin(), digits.end(), mn[mod][1]));
            } else return "";
        }
        sort(digits.begin(), digits.end());
        for(int i = digits.size()-1; i >= 0; i--) {
            ans.push_back('0' + digits[i]);
        }
        if(ans.size() != 0 && ans[0] == '0') return "0";
        return ans;
    }
};