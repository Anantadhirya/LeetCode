class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        set<pair<int, int>> s;
        for(int i = 0, j = 0; i < n; i++) {
            s.insert({nums[i], i});
            while((--s.end())->first - s.begin()->first > 2) {
                s.erase({nums[j], j});
                j++;
            }
            ans += (long long)(i-j+1);
        }
        return ans;
    }
};