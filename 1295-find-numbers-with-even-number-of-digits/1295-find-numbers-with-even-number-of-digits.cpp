class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0, digit = 0;
        for(int &i: nums) {
            digit = 0;
            while(i > 0) {
                i /= 10;
                digit++;
            }
            ans += (digit%2 == 0);
        }
        return ans;
    }
};