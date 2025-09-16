class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        int g;
        for(int &i: nums) {
            while(!ans.empty()) {
                g = __gcd(ans.back(), i);
                if(g == 1) break;
                i = i/g*ans.back();
                ans.pop_back();
            }
            ans.push_back(i);
        }
        return ans;
    }
};